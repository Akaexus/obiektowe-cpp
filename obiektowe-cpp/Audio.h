#pragma once
#include "Equipment.h"
#include <vector>
class Audio :
    public Equipment<double>
{
    protected:
        double power;
    private:
        double frequency_start;
        double frequency_end;
        std::vector<std::string> attribs = {
            "Power",
            "Frequency start",
            "Frequency end",
        };
    public:
        Audio();
        Audio(double pwr, double f_start, double f_end);
        virtual std::string about();
        virtual void importData(std::vector<std::string> v);
        virtual std::vector<std::string> exportData();
        virtual std::vector<std::string> getAttribNames();
};

