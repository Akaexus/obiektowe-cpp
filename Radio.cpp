#include "Radio.h"
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