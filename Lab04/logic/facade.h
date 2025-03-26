#ifndef FACADE_H
#define FACADE_H

#include "logic/file_readers/basefilereader.h"
#include "logic/math/point.h"
#include "logic/normalizationparameters.h"
#include "logic/scene/drawers/scenedrawerbase.h"
#include "logic/scene/camera/projection.h"
#include "logic/scene/scene.h"

class Facade
{
private:
    BaseFileReader* reader;
    Scene* _scene;
    SceneDrawerBase* drawer;

    Scene& scene();
public:
    Facade(SceneDrawerBase* drawer);
    ~Facade();

    void loadScene(const Str& path);
    void loadScene(const Str& path, const NormalizationParameters& params);
    void draw();
    void setTransform(const obj3d::Point& position, const obj3d::Point& rotation, const obj3d::Point& scale);
    void getTransform(obj3d::Point& position, obj3d::Point& rotation, obj3d::Point& scale);
    void setProjection(Projection* projection);
    bool isLoaded();
};

#endif // FACADE_H
