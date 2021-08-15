#pragma once

#include <objects/object.hpp>

class Landmark : public Object {

public:
  Landmark();  
  Landmark(Pos2D pos, double raduis);
  ~Landmark();  

  void draw();

private:
  double r;
};