#pragma once
#include "Equipment.h"
#include <string>
#include <array>

class Visual
	: public Equipment<double>
{
	private:
		std::array<int, 2> resolution = { 640, 480 };
	protected:
		std::string mode;
	public:
		Visual();
		Visual(std::string m, std::array<int, 2> res);
		bool setMode(std::string m);
		virtual int getNumberOfColors() = 0;
};

