#pragma once
#include "Audio.h"
class Radio :
    public Audio
{
    private:
        int memorySize = 5;
    protected:
        int speakers = 1;
    public:
        bool setMemorySize(int m);
        bool setSpeakers(int s);
        int getMemorySize();
        int getSpeakers();
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
};

