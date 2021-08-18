#include <stdafx.hpp>
#include <renderer/renderer.hpp>
#include <sensors/observed_data.hpp>
#include <objects/ideal_robot.hpp>

IdealRobot::IdealRobot(Pos2D p)
: Object(p)
{
}

IdealRobot::~IdealRobot() 
{
}

void IdealRobot::draw() {

  Object::draw();

  LOBJ obs;
  getSurroundingObjects(obs);
  for (auto o : obs) {
    Pos2D opos = o->getPos();
    GetGM().drawLine(pos.x, pos.y, opos.x, opos.y, 1.0, WHITE);
  }
}

void IdealRobot::update(double dt) {

  Agent::Input inp;
  if (agent) inp = agent->decision();

  prevPos = pos;
  pos = updatePose(pos, inp, dt);

  observed.clear();
  sensorData.clear();
}

Pos2D IdealRobot::updatePose(Pos2D prevPos, Agent::Input input, double dt) {

  Pos2D newPos = prevPos;

  newPos.x += input.vx*cos(prevPos.theta) * dt;
  newPos.y += input.vx*sin(prevPos.theta) * dt;
  newPos.theta += input.yawRate * dt;

  return newPos;
}

void IdealRobot::addCamera(ICAM_PTR camera) {
  cameras.push_back(camera);
}

void IdealRobot::getSurroundingObjects(LOBJ& objs) {

  if (observed.empty()) {
    updateSensorData();
    for (auto sd : sensorData) {
      double x = pos.x + sd->dis*cos(sd->dir);
      double y = pos.y + sd->dis*sin(sd->dir);
      auto obj = std::make_shared<Object>(Pos2D(x, y));
      observed.push_back(obj);
    }
  }

  objs.assign(observed.begin(), observed.end());
}

void IdealRobot::getSensorData(LOBS& obs) {

  if (sensorData.empty()) {
    updateSensorData();
  }

  obs.assign(sensorData.begin(), sensorData.end());
}

void IdealRobot::updateSensorData() {

  sensorData.clear();
  for (auto c : cameras) {
    LOBS obs;
    c->observation(obs);
    sensorData.insert(sensorData.cbegin(), obs.begin(), obs.end());      
  }
}
