#include "Visual.h"
#include <sstream>
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

std::string Visual::about()
{
	std::stringstream s;
	s << Equipment<double>::about();
	s << "Resolution: " << this->resolution[0] << "x" << this->resolution[1]
		<< "\nMode: " << this->mode << "\n";
	return s.str();
}

Visual::Visual(std::string m, std::array<int, 2> res)
{
	if (!this->setMode(m)) {
		this->setMode("PAL");
	}

	this->resolution = res;
}