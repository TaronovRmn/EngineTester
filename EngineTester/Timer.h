#pragma once
#include <chrono>
#include <ctime>
#include <mutex>
#include <shared_mutex>
class Timer
{
public:
	Timer();
	~Timer();
	void start();
	void stop();
	double elapsedMilliseconds();
	double elapsedSeconds();
private:
	std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	std::chrono::time_point<std::chrono::system_clock> m_EndTime;
	bool m_bRunning = false;
	std::shared_timed_mutex mtx;
};

