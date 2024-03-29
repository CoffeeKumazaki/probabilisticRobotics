#pragma once

class IdealRobot;
class PoseEstimator;

class Agent {

public:
  struct Input {
    double vx;
    double yawRate;
  };

  Agent(std::shared_ptr<IdealRobot> parent, std::shared_ptr<PoseEstimator> estimator);
  ~Agent();

  Input decision();
  Pos2D estimation(double dt);
  void draw();

  Pos2D getCurPos()    { return curPos; }
  Pos2D getPrevPos()   { return prevPos; }
  Input getPrevInput() { return prevInput; }

protected:
  std::shared_ptr<IdealRobot> parent;
  std::shared_ptr<PoseEstimator> estimator;
  Pos2D curPos;
  Pos2D prevPos;
  Input prevInput;
};

using AGENT_PTR = std::shared_ptr<Agent>;