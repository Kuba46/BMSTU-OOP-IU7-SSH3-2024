#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "logic/scene/camera/projection.h"

class Perspective : public Projection
{
public:
    Perspective() = default;
    Perspective(const Perspective& other) = default;

    obj3d::Point project(const obj3d::Point& point) override;
};

#endif // PERSPECTIVE_H
