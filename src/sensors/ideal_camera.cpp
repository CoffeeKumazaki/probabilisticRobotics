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

int IdealCamera::observation(LOBS& observed) {

  MAP_PTR map = World::getInstance().getMap();
  std::list<OBJ_PTR> objs;
  int nObs = map->getObjects(objs);

  for (auto o : objs) {
    auto obs = std::make_shared<ObservedData>();
    obs->sensorName = name;
    Pos2D oPos = o->getPos();
    Pos2D pPos = parent->getPos();
    double dx = oPos.x - (pPos.x + pose.x);
    double dy = oPos.y - (pPos.y + pose.y);
    obs->dis = sqrt(dx*dx + dy*dy);
    obs->dir = atan2(dy, dx);
    observed.push_back(obs);
  }

  return observed.size();
}
