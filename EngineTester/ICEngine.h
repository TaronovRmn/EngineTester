#pragma once
#include "IEngines.h"
#include "Timer.h"
#include <vector>
#include <atomic>
using namespace std;
class ICEngine :
	public IEngines
{
	double i = 0;
	vector<double> m;
	vector<double> v;
	double t_max = 10;
	double h_m = 0;
	double h_v = 0;
	double c = 0;
	atomic<double> t_curr = 0;
	atomic<double> elapsed_seconds = 0;
	atomic<bool> launched = false;
	Timer timer;
public:
	ICEngine();
	~ICEngine();
	void start(double& t_env) override;
	void stop() override;
	double getTemperature() override;
	double getElapsedTime() override;
	double getTMax() override;
};

