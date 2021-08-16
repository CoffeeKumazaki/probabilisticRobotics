#include <stdafx.hpp>
#include <renderer/renderer.hpp>
#include <world/world.hpp>
#include <objects/landmark.hpp>
#include <objects/robot.hpp>
#include <sensors/ideal_camera.hpp>

#define SIM_DT (0.1)

int main(int argc, char const *argv[]) {

	GetGM().init();
	GetGM().setBackgroundcolor(color(47, 39, 37, 255));

	World& world = World::getInstance();
	world.init();

	OBJ_PTR landmark1 = std::make_shared<Landmark>(Pos2D(100, 100), 10);

	world.getMap()->addObject(landmark1);

	auto robot = std::make_shared<Robot>(Pos2D(500, 500), Size2D(10, 30));
	ICAM_PTR camera = std::make_shared<IdealCamera>(robot, Pos2D(0,0));
	robot->addCamera(camera);
	world.addObject(robot);

	auto agent = std::make_shared<Agent>(robot);
	robot->setAgent(agent);

	// Main loop
	while (!GetGM().shouldCloseWindow())
	{
		GetGM().prerender();

		world.draw();
		world.update(SIM_DT);

		// Rendering
		GetGM().render();
	}

	GetGM().term();
	return 0;
}