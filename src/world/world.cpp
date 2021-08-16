#include <stdafx.hpp>
#include <world/world.hpp>

World::World() {

}

World::~World() {

}

void World::init() {
  map = std::make_shared<Map>();
}

void World::term() {
  map.reset();
}

void World::draw() {

  map->draw();

  for (auto o : obs) {
    o->draw();
  }
}

void World::update(double dt) {

  for (auto o : obs) {
    o->update(dt);
  }
}


void World::addObject(OBJ_PTR obj) {

  auto pos = std::find(obs.begin(), obs.end(), obj);
  if (pos == obs.end()) {
    obs.push_back(obj);
  }
}