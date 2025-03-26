#ifndef FIGURE_H
#define FIGURE_H

#include "../Exceptions/InputExceptions.hpp"
#include "../Exceptions/MenuExceptions.hpp"
#include "../Figures/Point.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <vector>

class Figure
{
public:
    virtual double getPerimeter() = 0;
    virtual void printInfo() = 0;
    virtual void printPerimeter() = 0;
    virtual ~Figure();

protected:
    std::string nameOfFigure;
};

#endif