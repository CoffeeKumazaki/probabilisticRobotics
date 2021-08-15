#pragma once

#include <objects/object.hpp>
#include <world/map.hpp>

class World {

public:
  static World& getInstance() {
    static World instance;
    return instance;
  }

private:
  World();
  ~World();

public:
  void init();
  void term();

  void draw();
  void addObject(OBJ_PTR obj);
  MAP_PTR getMap() { return map; }

private:
  std::list<OBJ_PTR> obs;
  MAP_PTR map;
};

