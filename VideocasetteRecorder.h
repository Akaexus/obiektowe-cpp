#pragma once
#include "Visual.h"
class VideocasetteRecorder :
    public Visual
{
    static const int DEFAULT_HEADS_NUMBER;
    static const bool DEFAULT_AUTO_CLEANING_HEADS;

    private:
        bool autoCleaningHeads;
    protected:
        int numberOfHeads;
    public:
        int getNumberOfHeads();
        bool setNumberOfHeads(int n);
        bool haveAutocleaningHeads();
        bool setAutocleaningHeads(bool ach);
        VideocasetteRecorder();
        VideocasetteRecorder(std::string mode, std::array <int, 2> res, int n, bool ach);
        int getNumberOfColors();
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
};

