#include <stdafx.hpp>
#include <renderer/renderer.hpp>
#include <objects/ideal_robot.hpp>

IdealRobot::IdealRobot(Pos2D p)
: Object(p)
{
}

IdealRobot::~IdealRobot() 
{
}

void IdealRobot::draw() {

  Object::draw();

  LOBJ obs;
  getSurroundingObjects(obs);
  for (auto o : obs) {
    Pos2D opos = o->getPos();
    GetGM().drawLine(pos.x, pos.y, opos.x, opos.y, 1.0, WHITE);
  }
}

void IdealRobot::update(double dt) {

  Agent::Input inp;
  if (agent) inp = agent->decision();

  prevPos = pos;
  pos = updatePose(pos, inp, dt);

  observated.clear();
}

Pos2D IdealRobot::updatePose(Pos2D prevPos, Agent::Input input, double dt) {

  Pos2D newPos = prevPos;

  newPos.x += input.vx*cos(prevPos.theta) * dt;
  newPos.y += input.vx*sin(prevPos.theta) * dt;
  newPos.theta += input.yawRate * dt;

  return newPos;
}

void IdealRobot::addCamera(ICAM_PTR camera) {
  cameras.push_back(camera);
}

void IdealRobot::getSurroundingObjects(LOBJ& obs) {

  if (observated.empty()) {
    for (auto c : cameras) {
      IdealCamera::CameraObservation obs;
      c->observation(obs);
      for (auto o : obs) {
        double ox = pos.x + o.distance*cos(o.direction);
        double oy = pos.y + o.distance*sin(o.direction);
        observated.push_back(
          std::make_shared<Object>(Pos2D(ox, oy))
        );
      }
    }
  }

  obs.assign(observated.begin(), observated.end());
}