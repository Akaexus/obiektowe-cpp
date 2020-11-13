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
	s << "Frequency: " << this->frequency_start << " - "
		<< this->frequency_end << "Hz\n";
	return s.str();
}
