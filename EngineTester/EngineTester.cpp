// EngineTester.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <shared_mutex>
#include <thread>
#include <atomic>
#include "Timer.h"
#include "IEngines.h"
#include "ICEngine.h"
#include "Stand.h"

using namespace std;

int main()
{
	double env_t = 10.0;
	Stand stand(env_t);
	IEngines* engine = new ICEngine();

	cout << stand.temperatureTest(engine) << endl;
	delete engine;

}

