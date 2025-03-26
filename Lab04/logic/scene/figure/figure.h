#ifndef FIGURE_H
#define FIGURE_H

#include "logic/scene/sceneobject.h"
#include "logic/scene/figure/components/vertex.h"
#include "logic/scene/figure/components/edge.h"
#include "logic/math/point.h"

#include <vector>

namespace obj3d {class Figure;}

class obj3d::Figure : public obj3d::SceneObject
{
public:
    Figure(const std::vector<obj3d::Vertex>& vertices, const std::vector<obj3d::Edge>& edges);
    Figure(const obj3d::Figure& figure) = delete;

    obj3d::Point position() const;
    void setPosition(const obj3d::Point& point);
    obj3d::Point rotation() const;
    void setRotation(const obj3d::Point& point);
    obj3d::Point scale() const;
    void setScale(const obj3d::Point& point);

    std::vector<obj3d::Vertex>& vertices();
    std::vector<obj3d::Edge>& edges();
    const std::vector<obj3d::Vertex>& vertices() const;
    const std::vector<obj3d::Edge>& edges() const;

    obj3d::Point transform(const obj3d::Point& point) const override;

private:
    obj3d::Point _position;
    obj3d::Point _rotation;
    obj3d::Point _scale;

    std::vector<obj3d::Vertex> _vertices;
    std::vector<obj3d::Edge> _edges;
};

#endif // FIGURE_H
