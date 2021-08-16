#pragma once

class IdealRobot;

class Agent {

public:
  struct Input {
    double vx;
    double yawRate;
  };

  Agent(std::shared_ptr<IdealRobot> parent);
  ~Agent();

  Input decision();
  void draw();

protected:
  std::shared_ptr<IdealRobot> parent;
};

using AGENT_PTR = std::shared_ptr<Agent>;