#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Figures/Figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(std::string n, Point TL, Point BR);

    double getPerimeter() override;
    void printInfo() override;
    void printPerimeter() override;

private:
    Point topLeft;
    Point bottomRight;
};

#endif // RECTANGLE_H
