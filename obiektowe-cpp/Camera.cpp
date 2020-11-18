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
        << "\nOptical zoom: " << this->getOpticalZoom() << "x\n";
    return s.str();
}

void Camera::importData(std::vector<std::string> v)
{
    if (v.size() >= 2) {
        std::vector<std::string> pv(v.begin() + 2, v.end());
        Visual::importData(pv);
        this->setFocalLength(std::stod(v[0]));
        this->setOpticalZoom(std::stod(v[1]));
    }
}

std::vector<std::string> Camera::exportData()
{
    std::vector<std::string> pv = Visual::exportData(), v = {
        std::to_string(this->getFocalLength()),
        std::to_string(this->getOpticalZoom()),
    };
    v.insert(v.end(), pv.begin(), pv.end());
    return v;
}

std::vector<std::string> Camera::getAttribNames()
{
    std::vector<std::string> parentAttribs = Visual::getAttribNames();
    parentAttribs.insert(parentAttribs.begin(), this->attribs.begin(), this->attribs.end());
    return parentAttribs;
}
