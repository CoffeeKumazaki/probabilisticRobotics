#pragma once

#include <objects/object.hpp>
#include <sensors/ideal_camera.hpp>
#include <agents/agent.hpp>

class IdealRobot : public Object {

public:
  IdealRobot(Pos2D pos);
  ~IdealRobot();

  void draw();
  void update(double dt);

  void addCamera(ICAM_PTR camera);
  void setAgent(AGENT_PTR a) { agent = a; }
  void getSurroundingObjects(LOBJ& obs);

public:
  LICAM cameras;
  AGENT_PTR agent;
  LOBJ observated;
};

using IROBOT_PTR = std::shared_ptr<IdealRobot>;