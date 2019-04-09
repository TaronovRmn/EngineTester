#include "ICEngine.h"



ICEngine::ICEngine()
{
}


ICEngine::~ICEngine()
{
}

inline void ICEngine::start(double& t_env) {
	chrono::time_point<chrono::system_clock> start_on;
	start_on = chrono::system_clock::now();
	timer.start();
	launched = true;
	thread([&]() {
		while (launched) {
			chrono::time_point<chrono::system_clock> curr_timer = std::chrono::system_clock::now();
			elapsed_seconds = timer.elapsedSeconds();
			t_curr = t_curr + 1.0;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		}).detach();

}

inline void ICEngine::stop() { launched = false; }

inline double ICEngine::getTemperature() { return t_curr; }

inline double ICEngine::getElapsedTime() { return elapsed_seconds; }

inline double ICEngine::getTMax() { return t_max; }
