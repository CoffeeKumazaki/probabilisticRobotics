#pragma once

#include <sensors/observed_data.hpp>
#include <agents/agent.hpp>

class IdealRobot;
class PoseEstimator {

public:
  PoseEstimator();
  ~PoseEstimator();

  virtual void init(Pos2D initPos) = 0;
  virtual Pos2D estimate(std::shared_ptr<IdealRobot> robot, double dt) = 0;
  virtual void draw() {};
};