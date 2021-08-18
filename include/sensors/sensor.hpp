#pragma once

#include <sensors/observed_data.hpp>
#include <objects/object.hpp>

class Sensor {

public:
  Sensor(OBJ_PTR parent, std::string name, Pos2D pose);
  ~Sensor();

  virtual int observation(Pos2D pos, LOBS& observed) = 0;
  virtual OBS_PTR observation(Pos2D pos, OBJ_PTR obj) = 0;
  std::string getName() { return name; }
  Pos2D getPose() {return pose;}

protected:
  OBJ_PTR parent;
  std::string name;
  Pos2D pose;
};

using SENSOR_PTR = std::shared_ptr<Sensor>;
using LSENSOR = std::list<SENSOR_PTR>;
using MSENSOR = std::map<std::string, SENSOR_PTR>;