#pragma once

#include <sensors/sensor.hpp>

class IdealCamera : public Sensor {

public:
  struct Observed {
    double distance = 0;
    double direction = 0;
  };
  using CameraObservation = std::list<Observed>;

public:
  IdealCamera(OBJ_PTR p, Pos2D pose);
  ~IdealCamera();

  virtual int observation(CameraObservation& observed);
};

using ICAM_PTR = std::shared_ptr<IdealCamera>;
using LICAM = std::list<ICAM_PTR>;