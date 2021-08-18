#pragma once

#include <sensors/sensor.hpp>

class IdealCamera : public Sensor {

public:
  IdealCamera(OBJ_PTR p, std::string name, Pos2D pose);
  ~IdealCamera();

  virtual int observation(LOBS& observed);
};

using ICAM_PTR = std::shared_ptr<IdealCamera>;
using LICAM = std::list<ICAM_PTR>;