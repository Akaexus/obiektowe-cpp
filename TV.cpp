#include "TV.h"
#include <sstream>

int TV::getNumberOfColors()
{
	if (this->mode == "SCAM") {
		return 600;
	}
	return 550;
}

double TV::getScreenRatio()
{
	return this->screenRatio;
}

int TV::getScreenSize()
{
	return this->screenSize;
}

bool TV::setScreenRatio(double ratio)
{
	if (ratio <= 0) {
		return false;
	}
	this->screenRatio = ratio;
	return true;
}

bool TV::setScreenSize(int size)
{
	if (size <= 0) {
		return false;
	}
	this->screenSize = size;
	return true;
}

std::string TV::about()
{
	std::stringstream s;
	s << Audio::about();
	s << Visual::about();
	s << "Number of colors: " << this->getNumberOfColors()
		<< "\nScreen ratio: " << this->getScreenRatio() << "\n";
	return s.str();
}


TV::TV()
{
	this->setScreenRatio(16.0 / 9.0);
	this->setScreenSize(21);
}


TV::TV(int size, double ratio)
{
	if (!this->setScreenSize(size)) {
		this->setScreenSize(21);
	}
	if (!this->setScreenRatio(ratio)) {
		this->setScreenRatio(16.0 / 9.0);
	}
}


void TV::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.begin() + 5);
		Audio::importData(pv);
		if (v.size() >= 5) {
			std::vector<std::string> pv2(v.begin() + 5, v.end());
			Visual::importData(pv2);
		}
		this->setScreenSize(std::stoi(v[0]));
		this->setScreenRatio(std::stod(v[1]));
	}
}

std::vector<std::string> TV::exportData()
{
	std::vector<std::string> pv = Audio::exportData(),
		pv2 = Visual::exportData(),
		v = {
		std::to_string(this->getScreenSize()),
		std::to_string(this->getScreenRatio()),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	v.insert(v.end(), pv2.begin(), pv2.end());
	return v;
}