// EngineTester.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Timer.h"
#include "IEngines.h"
#include "ICEngine.h"
#include "Stand.h"

using namespace std;

int main()
{
	double t_amb = 0; //input from console
	cout << "Enter the ambient temperature (C): ";
	cin >> t_amb;
	if (!std::cin) {
		std::cout << "bad format!" << std::endl;
		return 1;
	}

	double i;
	vector<double> m;
	vector<double> v;
	double t_max;
	double h_m;
	double h_v;
	double c;

	ifstream fin("configuration.txt");
	if (fin.is_open())
	{
		fin >> i;
		int k;
		fin >> k;
		for (int it = 0; it < k; it++) {
			double tmp;
			fin >> tmp;
			m.push_back(tmp);
		}
		for (int it = 0; it < k; it++) {
			double tmp;
			fin >> tmp;
			v.push_back(tmp);
		}
		fin >> t_max;
		fin >> h_m;
		fin >> h_v;
		fin >> c;
	}
	else {
		cout << "Configuration file not found!";
		return 2;
	}
	fin.close();

	Stand stand(t_amb);
	IEngines* engine = new ICEngine(i, m, v, t_max, h_m, h_v, c);
	cout << "Test started..." << endl;
	cout << "Engine overheated in " << stand.temperatureTest(engine) << " seconds." << endl;
	delete engine;
	return 0;

}

