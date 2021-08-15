#include <stdafx.hpp>
#include <renderer/renderer.hpp>
#include <world/world.hpp>
#include <objects/landmark.hpp>

int main(int argc, char const *argv[]) {

	GetGM().init();
	GetGM().setBackgroundcolor(color(47, 39, 37, 255));

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;

	World& world = World::getInstance();
	world.init();

	OBJ_PTR landmark1 = std::make_shared<Landmark>(Pos2D(100, 100), 10);

	world.getMap()->addObject(landmark1);

	// Main loop
	while (!GetGM().shouldCloseWindow())
	{
		GetGM().prerender();

		world.draw();

		// Rendering
		GetGM().render();
	}

	GetGM().term();
	return 0;
}
