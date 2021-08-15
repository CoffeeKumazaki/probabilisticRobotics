#pragma once

class Object {

public:
  Object();
  Object(Pos2D pos);
  ~Object();

  virtual void draw();

protected:
  Pos2D pos;
};

using OBJ_PTR = std::shared_ptr<Object>;