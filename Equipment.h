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
		T getVoltage();
		bool setVoltage(T v);
		virtual std::string about();

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
