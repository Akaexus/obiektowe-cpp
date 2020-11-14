#pragma once
#include <string>
#include <vector>
#include <sstream>
template <typename T>
class Equipment
{
	public:
		Equipment();
		T getCurrentFrequency();
		bool setCurrentFrequency(T f);
		T getVoltage();
		bool setVoltage(T v);
		virtual std::string about();
		virtual void importData(std::vector<std::string> v);
		virtual std::vector<std::string> exportData();
	protected:
		T voltage;
	private:
		T currentFrequency;
};

template<typename T>
inline Equipment<T>::Equipment()
{
	this->currentFrequency = (T)50;
	this->voltage = (T)230;
}

template<typename T>
inline T Equipment<T>::getCurrentFrequency()
{
	return this->currentFrequency;
}

template<typename T>
inline bool Equipment<T>::setCurrentFrequency(T f)
{
	if (f < 0) {
		return false;
	}
	this->currentFrequency = f;
	return false;
}

template<typename T>
inline T Equipment<T>::getVoltage()
{
	return this->voltage;
}

template<typename T>
inline bool Equipment<T>::setVoltage(T v)
{
	if (v > 0) {
		this->voltage = v;
		return true;
	}
	return false;
}

template<typename T>
inline std::string Equipment<T>::about()
{
	std::stringstream s;
	s << "Current frequency: " << this->getCurrentFrequency() << "Hz\n" <<
		"Voltage: " << this->getVoltage() << "V\n";
	return s.str();
}

template<typename T>
inline void Equipment<T>::importData(std::vector<std::string> v)
{
	if (v.size() == 2) {
		this->setVoltage(std::stod(v[0]));
		this->setCurrentFrequency(std::stod(v[1]));
	}
}

template<typename T>
inline std::vector<std::string> Equipment<T>::exportData()
{
	std::vector<std::string> v = {
		std::to_string(this->getVoltage()),
		std::to_string(this->getCurrentFrequency())
	};
	return v;
}
