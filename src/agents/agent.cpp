#include <stdafx.hpp>
#include <agents/agent.hpp>
#include <objects/ideal_robot.hpp>
#include <estimator/estimaror.hpp>
#include <renderer/renderer.hpp>

Agent::Agent(std::shared_ptr<IdealRobot> p, std::shared_ptr<PoseEstimator> e)
: parent(p)
, estimator(e)
{
  curPos = p->getPos();
  estimator->init(curPos);
}

Agent::~Agent() 
{
}

Agent::Input Agent::decision() {

  prevInput.vx = 10.0;
  prevInput.yawRate = M_PI/10.0;
  return prevInput;
}

Pos2D Agent::estimation(double dt) {

  prevPos = curPos;
  LOBS obs;
  parent->getSensorData(obs);
  curPos = estimator->estimate(parent, dt);
  return curPos;
}

void Agent::draw() {

  estimator->draw();
  GetGM().drawRectangle(curPos.x, curPos.y, parent->getSize().w, parent->getSize().h, curPos.theta, 1.0, RED);
}
