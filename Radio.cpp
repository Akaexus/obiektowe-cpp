#include "Radio.h"
#include <sstream>
#include <iostream>

int Radio::getFeatures()
{
	return 0;
}

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
