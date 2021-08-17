#include <stdafx.hpp>
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

void MCLEstimator::draw() {

  for (auto p : particles) {
    GetGM().fillCircle(p.pose.x, p.pose.y, 1, RED);
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


Pos2D MCLEstimator::estimate(Pos2D prevPos, Agent::Input input, double dt) {

  particles.clear();
  double ax = 0, ay = 0, at = 0;
  for (size_t i = 0; i < nParticle; i++) {
    Pos2D pos = robot->updatePose(prevPos, addNoise(input, dt), dt);
    particles.push_back(Particle(pos));
    ax += pos.x;
    ay += pos.y;
    at += pos.theta;
  }
  ax /= nParticle; ay /= nParticle; at /= nParticle;

  return Pos2D(ax, ay, at);
}