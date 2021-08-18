#pragma once

#include <objects/object.hpp>
#include <sensors/ideal_camera.hpp>
#include <agents/agent.hpp>

class IdealRobot : public Object {

public:
  IdealRobot(size_t id, Pos2D pos, Size2D s);
  ~IdealRobot();

  void draw();
  void update(double dt);

  void addSensor(SENSOR_PTR sensor);
  SENSOR_PTR getSensor(std::string name);
  void setAgent(AGENT_PTR a) { agent = a; }
  const AGENT_PTR getAgent() {return agent;}
  void getSurroundingObjects(LOBJ& objs);
  void getSensorData(LOBS& obs);
  Pos2D updatePose(Pos2D prevPos, Agent::Input input, double dt);

  Pos2D getPrevPos() { return prevPos; }
  Size2D getSize() { return size; }

private:
  void updateSensorData();

protected:
  Size2D size;
  Pos2D prevPos;
  MSENSOR sensors;
  AGENT_PTR agent;
  LOBJ observed;
  LOBS sensorData;
};

using IROBOT_PTR = std::shared_ptr<IdealRobot>;