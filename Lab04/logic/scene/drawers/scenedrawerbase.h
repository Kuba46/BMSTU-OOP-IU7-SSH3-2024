#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H

#include "logic/scene/scene.h"
#include "logic/scene/camera/projection.h"
#include "logic/math/point.h"

class SceneDrawerBase
{
private:
    Projection* projection;

protected:
    obj3d::Point project(const obj3d::Point& point);

public:
    SceneDrawerBase();
    virtual ~SceneDrawerBase();

    void setProjection(Projection* projection);

    virtual void draw(const Scene& scene) = 0;
};

#endif // SCENEDRAWERBASE_H
