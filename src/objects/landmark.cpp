#include <stdafx.hpp>
#include <objects/landmark.hpp>
#include <renderer/renderer.hpp>

Landmark::Landmark() 
: Object()
{
}

Landmark::Landmark(Pos2D p, double radius)
: Object(p)
, r(radius)
{
}

Landmark::~Landmark() {
}

void Landmark::draw() {

  GetGM().drawCircle(pos.x, pos.y, r, 1, WHITE);
}
