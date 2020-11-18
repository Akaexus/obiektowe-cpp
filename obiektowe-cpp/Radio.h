#pragma once
#include "Audio.h"
#include <vector>

class Radio :
    public Audio
{
    private:
        int memorySize = 5;
    protected:
        int speakers = 1;
        std::vector<std::string> attribs = {
            "Memory size",
            "Speakers",
        };
    public:
        bool setMemorySize(int m);
        bool setSpeakers(int s);
        int getMemorySize();
        int getSpeakers();
        Radio();
        Radio(int m, int s);
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
        std::vector<std::string> getAttribNames();
        int operator[](int x);
};

