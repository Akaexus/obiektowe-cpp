#include "TV.h"

int TV::getFeatures()
{
	return 0;
}

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