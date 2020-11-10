#include "Visual.h"
Visual::Visual()
{
	this->resolution[0] = 640;
	this->resolution[1] = 480;
	this->setMode("PAL");
}

bool Visual::setMode(std::string m)
{
	std::string availableModes[] = {
		"NTSC",
		"PAL",
		"SECAM"
	};
	for (int i = 0; i < (sizeof(availableModes) / sizeof(availableModes[0])); i++) {
		if (m == availableModes[i]) {
			this->mode = m;
			return true;
		}
	}
	return false;
}

Visual::Visual(std::string m, std::array<int, 2> res)
{
	if (!this->setMode(m)) {
		this->setMode("PAL");
	}

	this->resolution = res;
}