#include <stdafx.hpp>
#include <objects/landmark.hpp>
#include <renderer/renderer.hpp>

Landmark::Landmark(size_t id) 
: Object(id)
{
}

Landmark::Landmark(size_t id, Pos2D p, double radius)
: Object(id, p)
, r(radius)
{
}

Landmark::~Landmark() {
}

void Landmark::draw() {

  GetGM().drawCircle(pos.x, pos.y, r, 1, WHITE);
}
