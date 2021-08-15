#include <stdafx.hpp>
#include <objects/robot.hpp>
#include <renderer/renderer.hpp>

Robot::Robot(Pos2D p, Size2D s)
: Object(p)
, size(s)
{
}

Robot::~Robot() {

}

void Robot::draw() {

  GetGM().drawRectangle(pos.x, pos.y, size.w, size.h);
}