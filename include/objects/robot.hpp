#pragma once

#include <objects/object.hpp>

class Robot : public Object {

public:
  Robot(Pos2D p, Size2D s);
  ~Robot();

  void draw();

private:
  Size2D size;
};