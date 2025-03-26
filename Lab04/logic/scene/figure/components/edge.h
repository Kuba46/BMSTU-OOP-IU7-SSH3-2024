#ifndef EDGE_H
#define EDGE_H

#include "logic/scene/figure/components/vertex.h"
#include "logic/math/point.h"

#include <memory>

namespace obj3d {class Edge;}

class obj3d::Edge
{
public:
    Edge(const Vertex& begin, const obj3d::Vertex& end);

    obj3d::Vertex begin();
    obj3d::Vertex end();
    const obj3d::Vertex begin() const;
    const obj3d::Vertex end() const;

private:
    std::shared_ptr<obj3d::Point> _begin;
    std::shared_ptr<obj3d::Point> _end;
};

#endif // EDGE_H
