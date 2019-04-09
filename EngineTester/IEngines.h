#pragma once
class IEngines
{
public:
	virtual void start(double& t_env) = 0;
	virtual void stop() = 0;
	virtual double getTemperature() = 0;
	virtual double getElapsedTime() = 0;
	virtual double getTMax() = 0;
};

