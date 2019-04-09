#pragma once
#include "IEngines.h"
#include "Timer.h"
#include <vector>
#include <atomic>
#include <algorithm>
using namespace std;
class ICEngine :
	public IEngines
{
	double i_ = 0;
	vector<double> m_;
	vector<double> v_;
	double t_max_ = 10;
	double h_m_ = 0;
	double h_v_ = 0;
	double c_ = 0;
	atomic<double> t_curr = 0;
	atomic<double> elapsed_seconds = 0;
	atomic<bool> launched = false;
	Timer timer;
public:
	ICEngine(double i, vector<double> m, vector<double> v, double t_max, double h_m, double h_v, double c);
	~ICEngine();
	void start(double& t_env) override;
	void stop() override;
	double getTemperature() override;
	double getElapsedTime() override;
	double getTMax() override;
	double getMfromV(double v);
};

