#include "Radio.h"
#include <sstream>
#include <iostream>

bool Radio::setMemorySize(int m)
{
	if (m > 0) {
		this->memorySize = m;
		return true;
	}
	return false;
}

bool Radio::setSpeakers(int s)
{
	if (s >= 1) {
		this->speakers = s;
		return true;
	}
	return false;
}

int Radio::getMemorySize()
{
	return this->memorySize;
}

int Radio::getSpeakers()
{
	return this->speakers;
}

Equipment<double>* Radio::create(std::vector<std::string>)
{
	Equipment<double>* o = new Radio();
	return o;
}

std::string Radio::about()
{
	std::stringstream s;
	s << Audio::about();
	s << "Memory size: " << this->getMemorySize() << " slots\n"
		<< "Speakers: " << this->getSpeakers() << "\n";
	return s.str();
}

void Radio::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.end());
		Audio::importData(pv);
		this->setMemorySize(std::stoi(v[0]));
		this->setSpeakers(std::stoi(v[1]));
	}
}

std::vector<std::string> Radio::exportData()
{
	std::vector<std::string> pv = Audio::exportData(), v = {
		std::to_string(this->getMemorySize()),
		std::to_string(this->getSpeakers()),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}

std::vector<std::string> Radio::getAttribNames()
{
	std::vector<std::string> parentAttribs = Audio::getAttribNames();
	parentAttribs.insert(parentAttribs.begin(), this->attribs.begin(), this->attribs.end());
	return parentAttribs;
}