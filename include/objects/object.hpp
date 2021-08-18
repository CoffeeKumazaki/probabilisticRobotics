#pragma once

class Object {

public:
  Object(size_t id);
  Object(size_t id, Pos2D pos);
  ~Object();

  virtual void draw();
  virtual void update(double dt);
  size_t getId() { return id; }
  Pos2D getPos() { return pos; }

protected:
  size_t id;
  Pos2D pos;
};

using OBJ_PTR = std::shared_ptr<Object>;
using LOBJ = std::list<OBJ_PTR>;