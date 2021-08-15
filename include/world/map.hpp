#pragma once

#include <objects/object.hpp>

class Map {

public:
  Map();
  ~Map();

  void init();
  void draw();
  void addObject(OBJ_PTR obs);

private:
  std::list<OBJ_PTR> objs;
};

using MAP_PTR = std::shared_ptr<Map>;