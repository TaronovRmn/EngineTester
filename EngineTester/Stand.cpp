#include "Stand.h"


Stand::Stand(double& t) : t_amb(t) {}

double Stand::temperatureTest(IEngines* engine) {
	std::thread([&]() {
		engine->start(t_amb);
		while (engine->getTemperature() < engine->getTMax()) {
			//std::cout << engine->getTemperature() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		engine->stop();

		}).join();

		return engine->getElapsedTime();
}
