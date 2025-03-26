#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Figures/Figure.h"

class Triangle : public Figure
{
public:
    Triangle(std::string n, Point vertex1, Point vertex2, Point vertex3);

    double getPerimeter() override;
    void printInfo() override;
    void printPerimeter() override;

private:
    Point vertex1;
    Point vertex2;
    Point vertex3;
};

#endif // TRIANGLE_H
