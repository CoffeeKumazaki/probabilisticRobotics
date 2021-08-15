#pragma once

#include <objects/object.hpp>
#include <sensors/ideal_camera.hpp>

class IdealRobot : public Object {

public:
  IdealRobot(Pos2D pos);
  ~IdealRobot();

  void draw();
  void update();

  void addCamera(ICAM_PTR camera);

public:
  LICAM cameras;
};