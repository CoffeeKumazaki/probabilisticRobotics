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

  pos.x += inp.vx*cos(pos.theta) * dt;
  pos.y += inp.vx*sin(pos.theta) * dt;
  pos.theta += inp.yawRate * dt;

  observated.clear();
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