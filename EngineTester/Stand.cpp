#include "Stand.h"


Stand::Stand(double& t) : t_env(t) {}

double Stand::temperatureTest(IEngines* engine) {
	std::thread([&]() {
		engine->start(t_env);
		while (engine->getTemperature() < engine->getTMax()) {
			std::cout << engine->getTemperature() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		engine->stop();

		}).join();

		return engine->getElapsedTime();
}
