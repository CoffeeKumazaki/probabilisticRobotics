#pragma once

#include <sensors/sensor.hpp>

class IdealCamera : public Sensor {

public:
  IdealCamera(OBJ_PTR p, std::string name, Pos2D pose);
  ~IdealCamera();

  virtual int observation(Pos2D pos, LOBS& observed);
  virtual OBS_PTR observation(Pos2D pos, OBJ_PTR obj);
};

using ICAM_PTR = std::shared_ptr<IdealCamera>;
using LICAM = std::list<ICAM_PTR>;