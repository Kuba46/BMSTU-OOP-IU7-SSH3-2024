#include "logic/facade.h"
#include "logic/file_readers/filereader.h"
#include "logic/exceptions/scenenotloadedexception.h"

Facade::Facade(SceneDrawerBase* drawer)
{
    this->reader = new FileReader();
    this->_scene = new Scene();
    this->drawer = drawer;
}

Facade::~Facade()
{
    delete this->reader;
    delete this->_scene;
}

void Facade::loadScene(const Str& path)
{
    Scene* scene = new Scene(reader->read(path));
    delete this->_scene;
    this->_scene = scene;
    draw();
}

void Facade::loadScene(const Str& path, const NormalizationParameters& params)
{
    Scene* scene = new Scene(reader->read(path, params));
    delete this->_scene;
    this->_scene = scene;
    draw();
}

Scene& Facade::scene()
{
    if (!_scene) {
        throw SceneNotLoaded();
    }
    return *_scene;
}

void Facade::draw() {
    drawer->draw(scene());
}

void Facade::setTransform(const obj3d::Point& position, const obj3d::Point& rotation, const obj3d::Point& scale)
{
    Scene& scene = this->scene();
    for (std::shared_ptr<obj3d::Figure> figure : scene.figures())
    {
        figure->setPosition(position);
        figure->setRotation(rotation);
        figure->setScale(scale);
    }
    draw();
}

void Facade::getTransform(obj3d::Point& position, obj3d::Point& rotation, obj3d::Point& scale)
{
    if (!_scene || _scene->figures().size() == 0)
    {
        position = obj3d::Point(0, 0, 0);
        rotation = obj3d::Point(0, 0, 0);
        scale = obj3d::Point(1, 1, 1);
        return;
    }
    Scene& scene = this->scene();
    std::shared_ptr<obj3d::Figure> figure = scene.figures()[0];
    position = figure->position();
    rotation = figure->rotation();
    scale = figure->scale();
}

bool Facade::isLoaded()
{
    return _scene;
}

void Facade::setProjection(Projection* projection)
{
    this->drawer->setProjection(projection);
    draw();
}
