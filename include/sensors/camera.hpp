#pragma once

#include <sensors/ideal_camera.hpp>

class Camera : public IdealCamera {

public:
  Camera(OBJ_PTR p, Pos2D pose);
  ~Camera();

  virtual int observation(CameraObservation& observed);
  void setDistDev(double dev) { dist_dev = dev;}
  void setDirDev(double dev) { dir_dev = dev;}

private:
  double dist_dev;
  double dir_dev;
};

using CAMERA_PTR = std::shared_ptr<Camera>;