#include "ICEngine.h"



ICEngine::ICEngine(double i, vector<double> m, vector<double> v,
	double t_max, double h_m, double h_v, double c) : i_(i), m_(m), v_(v),
	t_max_(t_max), h_m_(h_m), h_v_(h_v), c_(c)
{
}


ICEngine::~ICEngine()
{
}

void ICEngine::start(double& t_amb) {
	chrono::time_point<chrono::system_clock> start_on;
	start_on = chrono::system_clock::now();
	timer.start();
	launched = true;
	t_curr = t_amb;
	thread([&]() {
		double v_i = 0;
		while (launched) {
			chrono::time_point<chrono::system_clock> curr_timer = chrono::system_clock::now();
			elapsed_seconds = timer.elapsedSeconds();

			double time_step = 1; //delta t in seconds

			double m_i = getMfromV(v_i); // get M from piecewise-linear function
			
			double v_h = m_i * h_m_ + (v_i * v_i) * h_v_; // Vh = M * Hm + V^2 * Hv
			double v_c = c_ * (t_amb - t_curr); // Vc = C * (Tamb - Teng)
			this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time_step*1000)));
			v_i = v_i + time_step * m_i / i_; // v = v0 + a * t, a = m / i
			t_curr = t_curr + time_step * v_h + time_step * v_c;
		}
		}).detach();

}

void ICEngine::stop() { launched = false; }

double ICEngine::getTemperature() { return t_curr; }

double ICEngine::getElapsedTime() { return elapsed_seconds; }

double ICEngine::getTMax() { return t_max_; }

double ICEngine::getMfromV(double v)
{
	// piecewise-linear approximation
	int top_i = distance(v_.begin(),lower_bound(v_.begin(), v_.end(), v));
	if (v == v_[top_i]) return m_[top_i];
	int bottom_i = top_i - 1;
	return ((v_[top_i] - v) / (v_[top_i] - v_[bottom_i])) * m_[bottom_i] + ((v - v_[bottom_i]) / (v_[top_i] - v_[bottom_i])) * m_[top_i];

}
