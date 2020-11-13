#include "StationaryTV.h"

bool StationaryTV::setSmart(bool s)
{
	return this->smart = s;
}

bool StationaryTV::setWifi(bool w)
{
	return this->wifi = w;
}

bool StationaryTV::haveWifi()
{
	return this->wifi;
}

bool StationaryTV::isSmart()
{
	return this->smart;
}

StationaryTV::StationaryTV()
{
	this->setSmart(false);
	this->setWifi(false);
}

StationaryTV::StationaryTV(int size, double r, bool s, bool w)
{
	this->setScreenSize(size);
	this->setScreenRatio(r);
	this->setSmart(s);
	this->setWifi(w);
}

Equipment<double> StationaryTV::create(std::vector<std::string>)
{
	return Equipment<double>();
}
