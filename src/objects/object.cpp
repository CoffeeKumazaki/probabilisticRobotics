#include <stdafx.hpp>
#include <objects/object.hpp>

Object::Object() 
{
}

Object::Object(Pos2D p)
: pos(p)
{
}

Object::~Object() {

}

void Object::draw() {
  
}

void Object::update(double dt) {

}