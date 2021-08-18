#include <stdafx.hpp>
#include <sensors/camera.hpp>

Camera::Camera(OBJ_PTR p, std::string name, Pos2D pose)
: IdealCamera(p, name, pose)
, dist_dev(0.01)
, dir_dev(0.01)
{
}

Camera::~Camera() {
}

int Camera::observation(LOBS& observed) {

  int num = IdealCamera::observation(observed);

  for (auto o : observed) {
    ObservedData pobs;
    o->dis = util::nrand(o->dis, o->dis*dist_dev);
    o->dir = util::nrand(o->dir, dir_dev);
  }
  return num;
}