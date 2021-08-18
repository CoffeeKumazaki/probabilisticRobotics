#include <stdafx.hpp>
#include <sensors/ideal_camera.hpp>
#include <world/world.hpp>

IdealCamera::IdealCamera(OBJ_PTR p, std::string name, Pos2D pose) 
: Sensor(p, name, pose)
{
}

IdealCamera::~IdealCamera()
{
}

int IdealCamera::observation(Pos2D pos, LOBS& observed) {

  MAP_PTR map = World::getInstance().getMap();
  std::list<OBJ_PTR> objs;
  int nObs = map->getObjects(objs);

  for (auto o : objs) {
    auto obs = observation(pos, o);
    observed.push_back(obs);
  }

  return observed.size();
}

OBS_PTR IdealCamera::observation(Pos2D pos, OBJ_PTR o) {

  auto obs = std::make_shared<ObservedData>();
  obs->sensorName = name;
  obs->objID = o->getId();
  Pos2D oPos = o->getPos();
  double dx = oPos.x - pos.x;
  double dy = oPos.y - pos.y;
  obs->dis = sqrt(dx*dx + dy*dy);
  obs->dir = atan2(dy, dx);

  return obs;
}