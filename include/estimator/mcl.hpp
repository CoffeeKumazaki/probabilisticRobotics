#pragma once

#include <estimator/estimaror.hpp>

class IdealRobot;

class MCLEstimator : public PoseEstimator {

  struct Particle {
    Pos2D pose;
    double weight;
    Particle(Pos2D pos, double w) {
      pose = pos;
      weight = w;
    }
  };

public:
  MCLEstimator(
    double sigma_vv = 0.1, double sigma_yy = 0.01, 
    double sigma_vy = 0.1, double sigma_yv = 0.01);
  ~MCLEstimator();

  void init(Pos2D initPos);
  void draw();

  Pos2D estimate(Pos2D prevPos, Agent::Input input, const LOBS& obs, double dt);
  Agent::Input addNoise(Agent::Input org, double dt);
  void setRobot(std::shared_ptr<IdealRobot> r) { robot = r; };

private:
  size_t nParticle;
  std::vector<std::shared_ptr<Particle>> particles;
  std::shared_ptr<IdealRobot> robot;

  double sigma_vv, sigma_yy, sigma_vy, sigma_yv;
};