#pragma once
#include "IEngines.h"
#include <thread>
#include <iostream>

class Stand {
	double t_amb = 0;
public:
	Stand(double& t);
	double temperatureTest(IEngines* engine);


};

