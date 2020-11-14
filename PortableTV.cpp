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

void PortableTV::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.end());
		TV::importData(pv);
		this->setWeight(std::stod(v[0]));
		this->setPortableAntenna(std::stoi(v[1]));
	}
}

std::vector<std::string> PortableTV::exportData()
{
	std::vector<std::string> pv = TV::exportData(), v = {
		std::to_string(this->getWeight()),
		std::to_string((int)this->isAntennaPortable()),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}