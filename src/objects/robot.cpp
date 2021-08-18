#include <stdafx.hpp>
#include <objects/robot.hpp>
#include <renderer/renderer.hpp>

Robot::Robot(size_t id, Pos2D p, Size2D s)
: IdealRobot(id, p, s)
{
  fp = util::erand(0.2);
  sigmaTheta = 0.01;
}

Robot::~Robot() {

}

void Robot::draw() {

  GetGM().drawRectangle(pos.x, pos.y, size.w, size.h, pos.theta, 1.0, WHITE);
  agent->draw();
  IdealRobot::draw();
}

void Robot::addNoise() {

  double dist = pos.distance(prevPos);
  fp -= dist;
  if (fp < 0.0) {
    pos.theta += util::nrand(0, sigmaTheta);
    fp += util::erand(0.2);
  }
} 

void Robot::update(double dt) {

  IdealRobot::update(dt);
  addNoise();

  agent->estimation(dt);
}