#include <stdafx.hpp>
#include <world/map.hpp>

Map::Map() {

  init();
}

Map::~Map() {

}

void Map::init() {
  objs.clear();
}

void Map::draw() {

  for (auto o : objs) {
    o->draw();
  }
}

void Map::addObject(OBJ_PTR obs) {

  auto pos = std::find(objs.begin(), objs.end(), obs);
  if (pos == objs.end()) {
    objs.push_back(obs);
  }
}

int Map::getObjects(std::list<OBJ_PTR>& o) {

  o.assign(objs.begin(), objs.end());
  return o.size();
}
