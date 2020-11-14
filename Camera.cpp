#include "Camera.h"
#include <sstream>

const double Camera::DEFAULT_FOCAL_LENGTH = 2.0;
const double Camera::DEFAULT_OPTICAL_ZOOM = 8.0;

double Camera::getFocalLength()
{
    return this->focalLength;
}

double Camera::getOpticalZoom()
{
    return this->opticalZoom;
}

bool Camera::setFocalLength(double f)
{
    if (f <= 0) {
        return false;
    }
    this->focalLength = f;
    return true;
}

bool Camera::setOpticalZoom(double z)
{
    if (z < 0) {
        return false;
    }
    this->opticalZoom = z;
    return true;
}

Camera::Camera()
{
    this->setFocalLength(Camera::DEFAULT_FOCAL_LENGTH);
    this->setOpticalZoom(Camera::DEFAULT_OPTICAL_ZOOM);
}

Camera::Camera(std::string mode, std::array<int, 2> res, double f, double z)
    :Visual(mode, res)
{
    if (!this->setFocalLength(f)) {
        this->setFocalLength(Camera::DEFAULT_FOCAL_LENGTH);
    }
    if (!this->setOpticalZoom(f)) {
        this->setOpticalZoom(Camera::DEFAULT_OPTICAL_ZOOM);
    }
}

int Camera::getNumberOfColors()
{
    return this->getFocalLength() * this->getOpticalZoom();
}

Equipment<double>* Camera::create(std::vector<std::string>)
{
    Camera* o = new Camera();
    return o;
}

std::string Camera::about()
{
    std::stringstream s;
    s << Visual::about();
    s << "Focal length: " << this->getFocalLength()
        << "Optical zoom: " << this->getOpticalZoom() << "x\n";
    return s.str();
}
