#include "StationaryTV.h"

bool StationaryTV::setSmart(bool s)
{
	return this->smart = s;
}

bool StationaryTV::setWifi(bool w)
{
	return this->wifi = w;
}

bool StationaryTV::haveWifi()
{
	return this->wifi;
}

bool StationaryTV::isSmart()
{
	return this->smart;
}

StationaryTV::StationaryTV()
{
	this->setSmart(false);
	this->setWifi(false);
}

StationaryTV::StationaryTV(int size, double r, bool s, bool w)
{
	this->setScreenSize(size);
	this->setScreenRatio(r);
	this->setSmart(s);
	this->setWifi(w);
}

Equipment<double>* StationaryTV::create(std::vector<std::string>)
{
	StationaryTV* o = new StationaryTV();
	return (Audio*)o;
}

std::string StationaryTV::about()
{
	std::stringstream s;
	s << TV::about();
	s << "Smart: " << (this->isSmart() ? "yes" : "no")
		<< "Wi-Fi: " << (this->haveWifi() ? "yes" : "no") << "\n";
	return s.str();
}

void StationaryTV::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.end());
		TV::importData(pv);
		this->setSmart(std::stoi(v[0]));
		this->setWifi(std::stoi(v[1]));
	}
}

std::vector<std::string> StationaryTV::exportData()
{
	std::vector<std::string> pv = TV::exportData(), v = {
		std::to_string((int)this->isSmart()),
		std::to_string((int)this->haveWifi()),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}