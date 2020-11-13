#include "TapeRecorder.h"

int TapeRecorder::getFeatures()
{
	return 0;
}

TapeRecorder::TapeRecorder()
	: Audio() {
	this->speed = 9.37;
	this->paths = 1;
}

TapeRecorder::TapeRecorder(double power, double f_start, double f_end, double spd, int pths)
	: Audio(power, f_start, f_end)
{
	if (spd < 0) {
		spd = 9.37;
	}
	this->speed = spd;
	if (pths < 0) {
		pths = 1;
	}
	this->paths = pths;
}

Equipment<double> TapeRecorder::create(std::vector<std::string>)
{
	return TapeRecorder();
}
