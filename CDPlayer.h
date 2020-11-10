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
    public:
        bool isRemoteIncluded();
        bool setDisplayColor(std::string color);
        std::string getDisplayColor();
        CDPlayer();
        CDPlayer(double power, double f_start, double f_end, bool remoteIncluded, std::string displayColor);
        int getFeatures();
};

