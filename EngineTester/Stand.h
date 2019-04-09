#pragma once
#include "IEngines.h"
#include <thread>
#include <iostream>

class Stand {
	double t_env = 0;
public:
	Stand(double& t);
	double temperatureTest(IEngines* engine);


};

