#pragma once
#include "Audio.h"
#include <string>

class CDPlayer :
    public Audio
{
    private:
        bool remoteIncluded;
    protected:
        std::string displayColor;
        std::vector<std::string> attribs = {
            "Remote included",
            "Display color",
        };
    public:
        bool isRemoteIncluded();
        bool setDisplayColor(std::string color);
        std::string getDisplayColor();
        CDPlayer();
        CDPlayer(double power, double f_start, double f_end, bool remoteIncluded, std::string displayColor);
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
        std::vector<std::string> getAttribNames();
};

