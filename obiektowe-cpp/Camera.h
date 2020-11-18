#pragma once
#include "Visual.h"
class Camera :
    public Visual
{
    static const double DEFAULT_FOCAL_LENGTH;
    static const double DEFAULT_OPTICAL_ZOOM;
    private:
        double focalLength;
    protected:
        double opticalZoom;
        std::vector<std::string> attribs = {
            "Focal length",
            "Optical zoom",
        };
    public:
        double getFocalLength();
        double getOpticalZoom();
        bool setFocalLength(double f);
        bool setOpticalZoom(double z);
        Camera();
        Camera(std::string mode, std::array<int, 2> res, double f, double z);
        static Equipment<double>* create(std::vector<std::string>);
        std::string about();
        void importData(std::vector<std::string> v);
        std::vector<std::string> exportData();
        std::vector<std::string> getAttribNames();
};

