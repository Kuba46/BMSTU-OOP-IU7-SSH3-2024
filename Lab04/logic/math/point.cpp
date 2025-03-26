#include "point.h"

obj3d::Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

obj3d::Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

obj3d::Point::Point(const obj3d::Point& point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

obj3d::Point& obj3d::Point::operator=(const obj3d::Point& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

double obj3d::Point::X() const {
    return x;
}

double obj3d::Point::Y() const {
    return y;
}

double obj3d::Point::Z() const {
    return z;
}

void obj3d::Point::setX(double x) {
    this->x = x;
}

void obj3d::Point::setY(double y) {
    this->y = y;
}

void obj3d::Point::setZ(double z) {
    this->z = z;
}
