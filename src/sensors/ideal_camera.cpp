#include <stdafx.hpp>
#include <sensors/ideal_camera.hpp>
#include <world/world.hpp>

IdealCamera::IdealCamera(OBJ_PTR p, Pos2D pose) 
: Sensor(p, pose)
{
}

IdealCamera::~IdealCamera()
{
}

int IdealCamera::observation(CameraObservation& observed) {

  MAP_PTR map = World::getInstance().getMap();
  std::list<OBJ_PTR> objs;
  int nObs = map->getObjects(objs);

  for (auto o : objs) {
    Observed obs;
    Pos2D oPos = o->getPos();
    Pos2D pPos = parent->getPos();
    double dx = oPos.x - (pPos.x + pose.x);
    double dy = oPos.y - (pPos.y + pose.y);
    obs.distance = sqrt(dx*dx + dy*dy);
    obs.direction = atan2(dy, dx);
    observed.push_back(obs);
  }

  return observed.size();
}
