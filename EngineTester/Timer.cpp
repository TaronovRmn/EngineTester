#include "Timer.h"

Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::start()
{
	std::shared_lock<std::shared_timed_mutex> lock(mtx);
	m_StartTime = std::chrono::system_clock::now();
	m_bRunning = true;
}

void Timer::stop()
{
	std::shared_lock<std::shared_timed_mutex> lock(mtx);
	m_EndTime = std::chrono::system_clock::now();
	m_bRunning = false;
}

double Timer::elapsedMilliseconds()
{
	std::shared_lock<std::shared_timed_mutex> lock(mtx);
	std::chrono::time_point<std::chrono::system_clock> endTime;

	if (m_bRunning)
	{
		endTime = std::chrono::system_clock::now();
	}
	else
	{
		endTime = m_EndTime;
	}

	return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

double Timer::elapsedSeconds()
{
	return elapsedMilliseconds() / 1000.0;
}


