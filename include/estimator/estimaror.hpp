#pragma once

#include <sensors/observed_data.hpp>
#include <agents/agent.hpp>

class PoseEstimator {

public:
  PoseEstimator();
  ~PoseEstimator();

  virtual void init(Pos2D initPos) = 0;
  virtual Pos2D estimate(Pos2D prevPos, Agent::Input input, const LOBS& obs, double dt) = 0;
  virtual void draw() {};
};