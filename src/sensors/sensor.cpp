#include <stdafx.hpp>
#include <sensors/sensor.hpp>

Sensor::Sensor(OBJ_PTR p, std::string _name, Pos2D _pose) 
: parent(p)
, name(_name)
, pose(_pose)
{
}

Sensor::~Sensor() {
}