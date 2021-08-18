#include <stdafx.hpp>
#include <objects/object.hpp>

Object::Object(size_t _id) 
: id(_id)
{
}

Object::Object(size_t _id, Pos2D p)
: id(_id)
, pos(p)
{
}

Object::~Object() {

}

void Object::draw() {
  
}

void Object::update(double dt) {

}