#include "logic/scene/camera/perspective.h"

#define PERSPECTIVE_COEFF 900

obj3d::Point Perspective::project(const obj3d::Point& point)
{
    if (point.Y() > 0)
    {
        return obj3d::Point(point.X() * PERSPECTIVE_COEFF /
                         (point.Y() + PERSPECTIVE_COEFF), point.Y(), point.Z() * PERSPECTIVE_COEFF / (point.Y() + PERSPECTIVE_COEFF));
    }
    else
    {
        return point;
    }
}
