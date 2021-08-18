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

int Camera::observation(Pos2D pos, LOBS& observed) {

  int num = IdealCamera::observation(pos, observed);

  for (auto o : observed) {
    o->dis = util::nrand(o->dis, o->dis*dist_dev);
    o->dir = util::nrand(o->dir, dir_dev);
    o->disErr = dist_dev;
    o->dirErr = dir_dev;
  }
  return num;
}