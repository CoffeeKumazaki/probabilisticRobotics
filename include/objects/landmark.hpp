#pragma once

#include <objects/object.hpp>

class Landmark : public Object {

public:
  Landmark(size_t id);  
  Landmark(size_t id, Pos2D pos, double raduis);
  ~Landmark();  

  void draw();

private:
  double r;
};