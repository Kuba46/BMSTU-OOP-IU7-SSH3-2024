#include "logic/scene/figure/components/edge.h"

obj3d::Edge::Edge(const obj3d::Vertex& begin, const obj3d::Vertex& end) : _begin(begin.pointer()), _end(end.pointer()) {}

obj3d::Vertex obj3d::Edge::begin()
{
    return obj3d::Vertex(_begin);
}

obj3d::Vertex obj3d::Edge::end()
{
    return obj3d::Vertex(_end);
}

const obj3d::Vertex obj3d::Edge::begin() const
{
    return obj3d::Vertex(_begin);
}

const obj3d::Vertex obj3d::Edge::end() const
{
    return obj3d::Vertex(_end);
}
