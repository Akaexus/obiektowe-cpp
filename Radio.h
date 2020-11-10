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
        int getFeatures();
        bool setMemorySize(int m);
        bool setSpeakers(int s);
        int getMemorySize();
        int getSpeakers();
};

