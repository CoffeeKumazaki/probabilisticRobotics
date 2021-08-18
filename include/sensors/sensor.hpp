#pragma once

#include <sensors/observed_data.hpp>
#include <objects/object.hpp>

class Sensor {

public:
  Sensor(OBJ_PTR parent, std::string name, Pos2D pose);
  ~Sensor();

protected:
  OBJ_PTR parent;
  std::string name;
  Pos2D pose;
};