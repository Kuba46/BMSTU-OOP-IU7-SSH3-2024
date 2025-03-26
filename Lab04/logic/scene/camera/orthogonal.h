#ifndef ORTHOGONAL_H
#define ORTHOGONAL_H

#include "logic/scene/camera/projection.h"

class Orthogonal : public Projection
{
public:
    Orthogonal() = default;
    Orthogonal(const Orthogonal& other) = default;

    obj3d::Point project(const obj3d::Point& point) override;
};

#endif // ORTHOGONAL_H
