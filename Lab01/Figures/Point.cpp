#include "../Figures/Point.h"

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}