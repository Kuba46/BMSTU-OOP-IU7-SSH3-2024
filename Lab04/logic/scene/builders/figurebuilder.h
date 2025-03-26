#ifndef FIGUREBUILDER_H
#define FIGUREBUILDER_H

#include "logic/scene/figure/figure.h"

#include <memory>

class FigureBuilder
{
public:
    virtual std::shared_ptr<obj3d::Figure> build() = 0;
};

#endif // FIGUREBUILDER_H
