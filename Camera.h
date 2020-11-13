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
    public:
        double getFocalLength();
        double getOpticalZoom();
        bool setFocalLength(double f);
        bool setOpticalZoom(double z);
        Camera();
        Camera(std::string mode, std::array<int, 2> res, double f, double z);
        int getNumberOfColors();
        static Equipment<double> create(std::vector<std::string>);
};

