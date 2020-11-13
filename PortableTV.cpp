#include "PortableTV.h"
double PortableTV::getWeight()
{
	return this->weight;
}

bool PortableTV::setWeight(double w)
{
	if (w <= 0) {
		return false;
	}
	this->weight = w;
	return true;
}

bool PortableTV::isAntennaPortable()
{
	return this->portableAntenna;
}

bool PortableTV::setPortableAntenna(bool a)
{
	this->portableAntenna = a;
	return true;
}

PortableTV::PortableTV()
{
	this->weight = 5;
	this->portableAntenna = true;
}


PortableTV::PortableTV(int size, double ratio, double w, double a)
	: TV(size, ratio)
{
	if (w <= 0) {
		this->weight = 5;
	}
	this->weight = w;
	
	this->portableAntenna = a;
}

Equipment<double> PortableTV::create(std::vector<std::string>)
{
	return Equipment<double>();
}
