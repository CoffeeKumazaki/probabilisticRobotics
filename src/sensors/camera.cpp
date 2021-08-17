#include <stdafx.hpp>
#include <sensors/camera.hpp>

Camera::Camera(OBJ_PTR p, Pos2D pose)
: IdealCamera(p, pose)
, dist_dev(0.01)
, dir_dev(0.01)
{
}

Camera::~Camera() {
}

int Camera::observation(CameraObservation& observed) {

  CameraObservation tmp;
  int num = IdealCamera::observation(tmp);

  for (auto o : tmp) {
    Observed pobs;
    pobs.distance  = util::nrand(o.distance, o.distance*dist_dev);
    pobs.direction = util::nrand(o.direction, dir_dev);
    observed.push_back(pobs);
  }
  return num;
}