#include "logic/scene/drawers/scenedrawerbase.h"
#include "logic/scene/camera/orthogonal.h"

SceneDrawerBase::SceneDrawerBase() {
    projection = new Orthogonal();
}

SceneDrawerBase::~SceneDrawerBase() {
    delete projection;
}

obj3d::Point SceneDrawerBase::project(const obj3d::Point& point) {
    return projection->project(point);
}

void SceneDrawerBase::setProjection(Projection* projection) {
    delete this->projection;
    this->projection = projection;
}
