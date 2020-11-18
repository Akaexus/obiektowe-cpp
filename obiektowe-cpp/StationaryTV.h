#pragma once
#include "TV.h"
class StationaryTV :
    public TV
{
    private:
        bool smart = false;
    protected:
        bool wifi = false;
        std::vector<std::string> attribs = {
            "SMART",
            "Wi-Fi",
        };
    public:
        bool setSmart(bool s);
        bool setWifi(bool w);
        bool haveWifi();
        bool isSmart();
        StationaryTV();
        StationaryTV(int size, double r, bool s, bool w);
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
        std::vector<std::string> getAttribNames();
};

