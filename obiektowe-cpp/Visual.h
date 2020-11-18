#pragma once
#include "Equipment.h"
#include <string>
#include <array>
#include <vector>

class Visual
	: public Equipment<double>
{
	private:
		std::array<int, 2> resolution = { 640, 480 };
	protected:
		std::string mode;
		std::vector<std::string> attribs = {
			"Horizontal resolution",
			"Vertical resolution",
			"Mode",
		};
	public:
		Visual();
		Visual(std::string m, std::array<int, 2> res);
		bool setMode(std::string m);
		virtual std::string about();
		virtual void importData(std::vector<std::string> v);
		virtual std::vector<std::string> exportData();
		virtual std::vector<std::string> getAttribNames();

};

