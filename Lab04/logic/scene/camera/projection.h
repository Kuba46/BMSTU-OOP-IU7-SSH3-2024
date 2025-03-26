#ifndef PROJECTION_H
#define PROJECTION_H

#include "logic/math/point.h"

class Projection
{
public:
    virtual ~Projection() = default;
    virtual obj3d::Point project(const obj3d::Point& point) = 0;
};

#endif // PROJECTION_H
