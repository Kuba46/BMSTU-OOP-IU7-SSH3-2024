#include "logic/scene/figure/figure.h"
#include "logic/math/matrix.h"
#include "logic/math/matrixbuilder.h"

obj3d::Figure::Figure(const std::vector<obj3d::Vertex>& vertices, const std::vector<obj3d::Edge>& edges) : _vertices(vertices), _edges(edges)
{
    _position = obj3d::Point(0, 0, 0);
    _rotation = obj3d::Point(0, 0, 0),
    _scale = obj3d::Point(1, 1, 1);
}

obj3d::Point obj3d::Figure::position() const
{
    return _position;
}
void obj3d::Figure::setPosition(const obj3d::Point& point)
{
    _position = point;
}

obj3d::Point obj3d::Figure::rotation() const
{
    return _rotation;
}

void obj3d::Figure::setRotation(const obj3d::Point& point)
{
    _rotation = point;
}

obj3d::Point obj3d::Figure::scale() const
{
    return _scale;
}

void obj3d::Figure::setScale(const obj3d::Point& point)
{
    _scale = point;
}

std::vector<obj3d::Vertex>& obj3d::Figure::vertices()
{
    return _vertices;
}

std::vector<obj3d::Edge>& obj3d::Figure::edges()
{
    return _edges;
}

const std::vector<obj3d::Vertex>& obj3d::Figure::vertices() const
{
    return _vertices;
}

const std::vector<obj3d::Edge>& obj3d::Figure::edges() const
{
    return _edges;
}

obj3d::Point obj3d::Figure::transform(const obj3d::Point& point) const
{
    obj3d::Matrix translate = MatrixBuilder::move(_position.X(), _position.Y(), _position.Z());
    obj3d::Matrix rotate = MatrixBuilder::rotation(_rotation.X(), _rotation.Y(), _rotation.Z());
    obj3d::Matrix scale = MatrixBuilder::scale(_scale.X(), _scale.Y(), _scale.Z());
    return rotate.transform(scale.transform(translate.transform(point)));
}
