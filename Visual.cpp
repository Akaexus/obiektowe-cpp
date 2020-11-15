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

void Visual::importData(std::vector<std::string> v)
{
	if (v.size() >= 3) {
		std::vector<std::string> pv(v.begin() + 3, v.end());
		Equipment<double>::importData(pv);
		this->resolution[0] = std::stod(v[0]);
		this->resolution[1] = std::stod(v[1]);
		this->mode = v[2];
	}
}

std::vector<std::string> Visual::exportData()
{

	std::vector<std::string> pv = Equipment<double>::exportData(), v = {
		std::to_string(this->resolution[0]),
		std::to_string(this->resolution[1]),
		this->mode,
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}

std::vector<std::string> Visual::getAttribNames()
{
	std::vector<std::string> parentAttribs = Equipment<double>::getAttribNames();
	parentAttribs.insert(parentAttribs.begin(), this->attribs.begin(), this->attribs.end());
	return parentAttribs;
}

Visual::Visual(std::string m, std::array<int, 2> res)
{
	if (!this->setMode(m)) {
		this->setMode("PAL");
	}

	this->resolution = res;
}