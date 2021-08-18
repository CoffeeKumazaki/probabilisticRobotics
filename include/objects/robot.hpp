#pragma once

#include <objects/ideal_robot.hpp>

class Robot : public IdealRobot {

public:
  Robot(size_t id, Pos2D p, Size2D s);
  ~Robot();

  void draw();
  void update(double dt);

private:
  void addNoise();

private:
  double fp; // distance until noise
  double sigmaTheta; // deviation of noise for theta
};