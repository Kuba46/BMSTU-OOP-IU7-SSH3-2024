#ifndef VERTEX_H
#define VERTEX_H

#include "logic/math/point.h"
#include <memory>

namespace obj3d {class Vertex;}

class obj3d::Vertex
{
private:
    std::shared_ptr<obj3d::Point> _position;
public:
    Vertex(const obj3d::Point& point);
    Vertex(const std::shared_ptr<obj3d::Point>& point);
    Vertex(const obj3d::Vertex& vertex);

    obj3d::Point position() const;
    void setPosition(const obj3d::Point& point);

    std::shared_ptr<obj3d::Point> pointer();
    const std::shared_ptr<obj3d::Point> pointer() const;
};

#endif // VERTEX_H
