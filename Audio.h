#pragma once
#include "Equipment.h"
class Audio :
    Equipment<double>
{
    protected:
        double power;
    private:
        double frequency_start;
        double frequency_end;
    public:
        Audio();
        Audio(double pwr, double f_start, double f_end);
        virtual int getFeatures() = 0;
};

