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

void VideocasetteRecorder::importData(std::vector<std::string> v)
{
    if (v.size() >= 2) {
        std::vector<std::string> pv(v.begin() + 2, v.end());
        Visual::importData(pv);
        this->setAutocleaningHeads(std::stoi(v[0]));
        this->setNumberOfHeads(std::stoi(v[1]));
    }
}

std::vector<std::string> VideocasetteRecorder::exportData()
{
    std::vector<std::string> pv = Visual::exportData(), v = {
        std::to_string((int)this->haveAutocleaningHeads()),
        std::to_string(this->getNumberOfHeads()),
    };
    v.insert(v.end(), pv.begin(), pv.end());
    return v;
}

std::vector<std::string> VideocasetteRecorder::getAttribNames()
{
    std::vector<std::string> parentAttribs = Visual::getAttribNames();
    parentAttribs.insert(parentAttribs.begin(), this->attribs.begin(), this->attribs.end());
    return parentAttribs;
}
