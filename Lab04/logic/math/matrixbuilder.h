#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include "logic/math/matrix.h"

class MatrixBuilder
{
public:
    static obj3d::Matrix identity();
    static obj3d::Matrix rotation(double x, double y, double z);
    static obj3d::Matrix move(double x, double y, double z);
    static obj3d::Matrix scale(double x, double y, double z);

private:
    static constexpr double degToRad = 1.0 / 180.0 * M_PI;
};

#endif // MATRIXBUILDER_H
