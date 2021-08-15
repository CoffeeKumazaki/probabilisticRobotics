#include <stdafx.hpp>
#include <sensors/sensor.hpp>

Sensor::Sensor(OBJ_PTR p, Pos2D _pose) 
: parent(p)
, pose(_pose)
{
}

Sensor::~Sensor() {
}