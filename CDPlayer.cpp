#include "CDPlayer.h"
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

int CDPlayer::getFeatures()
{
	return 0;
}

Equipment<double> CDPlayer::create(std::vector<std::string>)
{
	return CDPlayer();
}
