#pragma once
#include "TV.h"
#include <vector>

class PortableTV :
    public TV
{
    private:
        double weight;
    protected:
        bool portableAntenna;
        std::vector<std::string> attribs = {
            "Weight",
            "Portable antenna",
        };
    public:
        double getWeight();
        bool setWeight(double w);
        bool isAntennaPortable();
        bool setPortableAntenna(bool a);
        PortableTV();
        PortableTV(int size, double ratio, double w, double a);
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
        std::vector<std::string> getAttribNames();
};

