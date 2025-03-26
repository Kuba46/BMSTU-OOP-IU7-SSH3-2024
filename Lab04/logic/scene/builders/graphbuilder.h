#ifndef GRAPHBUILDER_H
#define GRAPHBUILDER_H

#include "logic/scene/builder/figurebuilder.h"
#include "logic/scene/figure/figure.h"

class GraphBuilder : public FigureBuilder
{
private:
    std::vector<std::vector<double>>& values;

public:
    GraphBuilder(std::vector<std::vector<double>>& values);

    std::shared_ptr<obj3d::Figure> build() override;
};

#endif // GRAPHBUILDER_H
