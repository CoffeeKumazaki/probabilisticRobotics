#pragma once

#include <objects/object.hpp>

class Sensor {

public:
  Sensor(OBJ_PTR parent, Pos2D pose);
  ~Sensor();

protected:
  OBJ_PTR parent;
  Pos2D pose;
};