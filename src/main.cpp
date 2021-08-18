#include <stdafx.hpp>
#include <renderer/renderer.hpp>
#include <world/world.hpp>
#include <objects/landmark.hpp>
#include <objects/robot.hpp>
#include <sensors/camera.hpp>
#include <estimator/mcl.hpp>

#define TIME_INTERVAL (0.1)

int main(int argc, char const *argv[]) {

	GetGM().init();
	GetGM().setBackgroundcolor(color(47, 39, 37, 255));

	World& world = World::getInstance();
	world.init();

	OBJ_PTR landmark1 = std::make_shared<Landmark>(100, Pos2D(100, 100), 10);
	OBJ_PTR landmark2 = std::make_shared<Landmark>(101, Pos2D(500, 100), 10);

	world.getMap()->addObject(landmark1);
	world.getMap()->addObject(landmark2);

	for (size_t i = 0; i < 1; i++)
	{
		auto robot = std::make_shared<Robot>(i, Pos2D(500, 500), Size2D(10, 30));
		ICAM_PTR camera = std::make_shared<Camera>(robot, "camera 01", Pos2D(0,0));
		robot->addSensor(camera);
		world.addRobot(robot);
		auto estimator = std::make_shared<MCLEstimator>();
		auto agent = std::make_shared<Agent>(robot, estimator);
		robot->setAgent(agent);
	}


	// Main loop
	while (!GetGM().shouldCloseWindow())
	{
		GetGM().prerender();

		world.draw();
		world.update(TIME_INTERVAL);

		// Rendering
		GetGM().render();
	}

	GetGM().term();
	return 0;
}
