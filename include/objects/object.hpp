#pragma once

class Object {

public:
  Object();
  Object(Pos2D pos);
  ~Object();

  virtual void draw();
  virtual void update();
  Pos2D getPos() { return pos; }

protected:
  Pos2D pos;
};

using OBJ_PTR = std::shared_ptr<Object>;