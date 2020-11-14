#include "Audio.h"
#include <sstream>

Audio::Audio() {
	this->power = 15;
	this->frequency_start = 20;
	this->frequency_end = 20000;
}

Audio::Audio(double pwr, double f_start, double f_end)
{
	if (pwr < 0) {
		pwr = -pwr;
	}
	this->power = pwr;

	if (f_start < 0) {
		f_start = 0;
	}
	if (f_end < 0) {
		f_end = 0;
	}

	if (f_start > f_end) {
		this->frequency_start = f_end;
		this->frequency_end = f_start;
	}
	else {
		this->frequency_start = f_start;
		this->frequency_end = f_end;
	}
}

std::string Audio::about()
{
	std::stringstream s;
	s << Equipment<double>::about();
	s << "Frequency: " << this->frequency_start << " - "
		<< this->frequency_end << "Hz"
		<< "\nPower: " << this->power << "W\n";
	return s.str();
}
// Audio | Equipment<double>
void Audio::importData(std::vector<std::string> v)
{
	if (v.size() >= 3) {
		std::vector<std::string> pv(v.begin() + 3, v.end());
		Equipment<double>::importData(pv);
		this->power = std::stod(v[0]);
		this->frequency_start = std::stod(v[1]);
		this->frequency_end = std::stod(v[2]);
	}
}

std::vector<std::string> Audio::exportData()
{
	std::vector<std::string> pv = Equipment<double>::exportData(), v = {
		std::to_string(this->power),
		std::to_string(this->frequency_start),
		std::to_string(this->frequency_end),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}
