#include <stdafx.hpp>
#include <util/gaussian.hpp>
#include <world/world.hpp>
#include <estimator/mcl.hpp>
#include <objects/ideal_robot.hpp>
#include <renderer/renderer.hpp>

MCLEstimator::MCLEstimator(double svv, double syy, double svy, double syv) 
: nParticle(100)
, sigma_vv(svv)
, sigma_yy(syy)
, sigma_vy(svy)
, sigma_yv(syv)
{
  particles.clear();
}

MCLEstimator::~MCLEstimator() {
  
}

void MCLEstimator::init(Pos2D initPos) {

  particles.clear();
  for (size_t i = 0; i < nParticle; i++) {
    particles.push_back(std::make_shared<Particle>(initPos, 1.0/nParticle));
  }
}

void MCLEstimator::draw() {

  for (auto p : particles) {
    GetGM().fillCircle(p->pose.x, p->pose.y, 1, RED);
  }
}

Agent::Input MCLEstimator::addNoise(Agent::Input org, double dt) {

  Agent::Input newInput;
  
  double dvv = util::nrand(0, sigma_vv); double dvy = util::nrand(0, sigma_vy);
  double dyv = util::nrand(0, sigma_yv); double dyy = util::nrand(0, sigma_yy);
  double cv = sqrt(abs(org.vx)/dt);
  double cy = sqrt(abs(org.yawRate)/dt);

  newInput.vx = org.vx + (dvv*cv + dvy*cy);
  newInput.yawRate = org.yawRate + (dyv*cv + dyy*cy);
  
  // std::cout << "org input " << org.vx << ", " << org.yawRate << std::endl;
  // std::cout << "new input " << newInput.vx << ", " << newInput.yawRate << std::endl;
  return newInput;
}

Pos2D MCLEstimator::estimate(IROBOT_PTR robot, double dt) {

  Pos2D likeliPos;
  double likelihood = 0;
  for (auto p : particles) {
    updatePose(p.get(), robot->getAgent()->getPrevInput(), dt);
    updateWeight(p.get(), robot);
    if (likelihood < p->weight) {
      likelihood = p->weight;
      likeliPos = p->pose;
    }
  }
  resampling();

  return likeliPos;
}

void MCLEstimator::updatePose(Particle* p, Agent::Input input, double dt) {

  p->pose = robot->updatePose(p->pose, addNoise(input, dt), dt);
}

void MCLEstimator::updateWeight(Particle* p, IROBOT_PTR robot) {

  auto map = World::getInstance().getMap();
  LOBJ objs;
  map->getObjects(objs);
  
  LOBS observed;
  robot->getSensorData(observed);
  for ( auto o : observed) {
    auto sensor = robot->getSensor(o->sensorName);

    OBS_PTR pobs;
    for (auto obj : objs) {
      if (obj->getId() == o->objID){
        pobs = sensor->observation(p->pose + sensor->getPose(), obj);
        break;
      }
    }

    Eigen::MatrixXd cov(2, 2);
    cov << (o->dis * o->disErr)*(o->dis * o->disErr), 0.0
        , 0.0, (o->dirErr)*(o->dirErr);

    Eigen::VectorXd mu(2); 
    mu << pobs->dis, pobs->dir;

    Eigen::VectorXd x(2);
    x << o->dis, o->dir;
    p->weight *= util::gaussian2D(x, mu, cov);
  }
}

void MCLEstimator::resampling() {

  double weightSum = 0;
  for ( auto p : particles) {
    weightSum += p->weight;
  }

  VP newParticles;  
  for (size_t i = 0; i < nParticle; i++) {
    double rand = util::urand(0.0, weightSum);
    double acc = 0;
    for (auto p : particles) {
      acc += p->weight;
      if (acc >= rand ) {
        newParticles.push_back(std::make_shared<Particle>(p->pose, 1.0/nParticle));
        break;
      }
    }
  }

  particles.assign(newParticles.begin(), newParticles.end());

}