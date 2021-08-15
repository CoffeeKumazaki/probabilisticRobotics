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

  for (auto c : cameras) {
    IdealCamera::CameraObservation obs;
    c->observation(obs);
    for (auto o : obs) {
      double ox = pos.x + o.distance*cos(o.direction);
      double oy = pos.y + o.distance*sin(o.direction);
      GetGM().drawLine(pos.x, pos.y, ox, oy, 1.0, WHITE);
    }
  }

}

void IdealRobot::update() {

}

void IdealRobot::addCamera(ICAM_PTR camera) {
  cameras.push_back(camera);
}