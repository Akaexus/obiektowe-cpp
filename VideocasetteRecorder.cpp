#include "VideocasetteRecorder.h"
#include <sstream>

const int VideocasetteRecorder::DEFAULT_HEADS_NUMBER = 1;
const bool VideocasetteRecorder::DEFAULT_AUTO_CLEANING_HEADS = false;

int VideocasetteRecorder::getNumberOfHeads()
{
    return this->numberOfHeads;
}

bool VideocasetteRecorder::setNumberOfHeads(int n)
{
    if (n < 1) {
        return false;
    }
    this->numberOfHeads = n;
    return true;
}

bool VideocasetteRecorder::haveAutocleaningHeads()
{
    return this->autoCleaningHeads;
}

bool VideocasetteRecorder::setAutocleaningHeads(bool ach)
{
    return this->autoCleaningHeads = ach;
}

VideocasetteRecorder::VideocasetteRecorder()
{
    this->setAutocleaningHeads(VideocasetteRecorder::DEFAULT_AUTO_CLEANING_HEADS);
    this->setNumberOfHeads(VideocasetteRecorder::DEFAULT_HEADS_NUMBER);
}

VideocasetteRecorder::VideocasetteRecorder(std::string mode, std::array<int, 2> res, int n, bool ach)
    :Visual(mode, res)
{
    if (!this->setAutocleaningHeads(ach)) {
        this->setAutocleaningHeads(VideocasetteRecorder::DEFAULT_AUTO_CLEANING_HEADS);
    }
    if (!this->setNumberOfHeads(n)) {
        this->setNumberOfHeads(VideocasetteRecorder::DEFAULT_HEADS_NUMBER);
    }
}

int VideocasetteRecorder::getNumberOfColors()
{
    int n = this->getNumberOfHeads() * 1024;
    return n + n * this->haveAutocleaningHeads();
}

Equipment<double>* VideocasetteRecorder::create(std::vector<std::string>)
{
    VideocasetteRecorder* o = new VideocasetteRecorder();
    return o;
}

std::string VideocasetteRecorder::about()
{
    std::stringstream s;
    s << Visual::about();
    s << "Number of heads: " << this->getNumberOfHeads()
        << "Autocleaning heads: " << (this->haveAutocleaningHeads() ? "yes" : "no") << "\n";
    return s.str();
}

