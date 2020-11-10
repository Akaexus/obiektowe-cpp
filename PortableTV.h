#pragma once
#include "TV.h"
class PortableTV :
    public TV
{
    private:
        double weight;
    protected:
        bool portableAntenna;
    public:
        double getWeight();
        bool setWeight(double w);
        bool isAntennaPortable();
        bool setPortableAntenna(bool a);
        PortableTV();
        PortableTV(int size, double ratio, double w, double a);
};

