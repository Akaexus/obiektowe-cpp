#pragma once
#include "Audio.h"
class TapeRecorder :
    public Audio
{
    protected:
        double speed; // cm/s
    private:
        int paths;
    public:
        int getFeatures();
        TapeRecorder();
        TapeRecorder(double power, double f_start, double f_end, double spd, int pths);
        static Equipment<double> create(std::vector<std::string>);
};

