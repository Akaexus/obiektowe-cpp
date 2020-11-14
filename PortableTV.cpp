#include "PortableTV.h"
#include <sstream>
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

Equipment<double>* PortableTV::create(std::vector<std::string>)
{
	PortableTV* o = new PortableTV();
	return (Audio*)o;
}

std::string PortableTV::about()
{
	std::stringstream s;
	s << TV::about();
	s << "Weight: " << this->getWeight()
		<< "\nPortable antenna: " << (this->isAntennaPortable() ? "yes" : "no") << "\n";
	return s.str();
}
