#include <stdafx.hpp>
#include <objects/robot.hpp>
#include <renderer/renderer.hpp>

Robot::Robot(Pos2D p, Size2D s)
: IdealRobot(p)
, size(s)
{
}

Robot::~Robot() {

}

void Robot::draw() {

  GetGM().drawRectangle(pos.x, pos.y, size.w, size.h, 1.0, WHITE);
  IdealRobot::draw();
}

void Robot::update() {

}