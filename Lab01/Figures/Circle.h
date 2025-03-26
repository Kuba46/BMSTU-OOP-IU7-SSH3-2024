#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Figures/Figure.h"

class Circle : public Figure
{
public:
    Circle(std::string n, Point center, double radius);

    double getPerimeter() override;
    void printInfo() override;
    void printPerimeter() override;

private:
    Point centerCoordinates;
    double radius;
};

#endif
