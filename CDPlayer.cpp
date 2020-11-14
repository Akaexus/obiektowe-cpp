#include "CDPlayer.h"
#include <sstream>

bool CDPlayer::isRemoteIncluded()
{
	return this->remoteIncluded;
}

std::string CDPlayer::getDisplayColor()
{
	return this->displayColor;
}

bool CDPlayer::setDisplayColor(std::string color)
{
	std::string colors[] = {
		"blue",
		"red",
		"green",
		"dark"
	};
	for (int i = 0; i < (sizeof(colors) / sizeof(colors[0])); i++) {
		if (color == colors[i]) {
			this->displayColor = color;
			return true;
		}
	}
	return false;
}

CDPlayer::CDPlayer()
	:Audio()
{
	this->remoteIncluded = false;
	this->displayColor = "blue";
}

CDPlayer::CDPlayer(double power, double f_start, double f_end, bool remoteIncluded, std::string displayColor)
	:Audio(power, f_start, f_end)
{
	this->remoteIncluded = remoteIncluded;
	if (!this->setDisplayColor(displayColor)) {
		this->setDisplayColor("blue");
	}

}


Equipment<double>* CDPlayer::create(std::vector<std::string>)
{
	CDPlayer* o = new CDPlayer();
	return o;
}

std::string CDPlayer::about()
{
	std::stringstream s;
	s << Audio::about();
	s << "Remote included: " << (this->isRemoteIncluded() ? "yes" : "no")
		<< "\nDisplay color: " << this->getDisplayColor() << "\n";
	return s.str();
}

void CDPlayer::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.end());
		Audio::importData(pv);
		this->remoteIncluded = std::stoi(v[0]);
		this->setDisplayColor(v[1]);
	}
}

std::vector<std::string> CDPlayer::exportData()
{
	std::vector<std::string> pv = Audio::exportData(), v = {
		std::to_string((int)this->isRemoteIncluded()),
		this->getDisplayColor(),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}
