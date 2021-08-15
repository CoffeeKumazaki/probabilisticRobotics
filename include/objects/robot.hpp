#pragma once

#include <objects/ideal_robot.hpp>

class Robot : public IdealRobot {

public:
  Robot(Pos2D p, Size2D s);
  ~Robot();

  void draw();
  void update();

private:
  Size2D size;
};