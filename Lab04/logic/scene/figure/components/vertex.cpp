#include "vertex.h"

obj3d::Vertex::Vertex(const obj3d::Point& point)
{
    _position = std::make_shared<obj3d::Point>(point);
}

obj3d::Vertex::Vertex(const std::shared_ptr<obj3d::Point>& point)
{
    _position = point;
}

obj3d::Vertex::Vertex(const Vertex& vertex)
{
    _position = vertex._position;
}

obj3d::Point obj3d::Vertex::position() const
{
    return *_position;
}

void obj3d::Vertex::setPosition(const obj3d::Point& point)
{
    *_position = point;
}

const std::shared_ptr<obj3d::Point> obj3d::Vertex::pointer() const
{
    return _position;
}

std::shared_ptr<obj3d::Point> obj3d::Vertex::pointer()
{
    return _position;
}
