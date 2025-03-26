#ifndef POINT_H
#define POINT_H

#include <cmath>

namespace obj3d {class Point;}

class obj3d::Point
{
private:
    double x;
    double y;
    double z;
public:
    Point();
    Point(double x, double y, double z);
    Point(const obj3d::Point& point);

    obj3d::Point& operator=(const obj3d::Point& other);

    double X() const;
    double Y() const;
    double Z() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
};

#endif // POINT_H
