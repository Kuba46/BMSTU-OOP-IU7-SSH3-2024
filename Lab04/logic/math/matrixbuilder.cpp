#include "matrixbuilder.h"
#include <cmath>

obj3d::Matrix MatrixBuilder::identity()
{
    obj3d::Matrix matrix;
    for (int i = 0; i < obj3d::Matrix::size; i++)
    {
        for (int j = 0; j < obj3d::Matrix::size; j++)
        {
            matrix.set(i, j, i == j);
        }
    }
    return matrix;
}

obj3d::Matrix MatrixBuilder::rotation(double x, double y, double z)
{
    obj3d::Matrix Mx({
               {1, 0, 0, 0},
               {0, std::cos(x * degToRad), -std::sin(x * degToRad), 0},
               {0, std::sin(x * degToRad), std::cos(x * degToRad), 0},
               {0, 0, 0, 1}
    });
    obj3d::Matrix My({
               {std::cos(y * degToRad), 0, std::sin(y * degToRad), 0},
               {0, 1, 0, 0},
               {-std::sin(y * degToRad), 0, std::cos(y * degToRad), 0},
               {0, 0, 0, 1}
    });
    obj3d::Matrix Mz({
               {std::cos(z * degToRad), -std::sin(z * degToRad), 0, 0},
               {std::sin(z * degToRad), std::cos(z * degToRad), 0, 0},
               {0, 0, 1, 0},
               {0, 0, 0, 1}
    });
    return Mx * My * Mz;
}

obj3d::Matrix MatrixBuilder::move(double x, double y, double z)
{
    return obj3d::Matrix({
                {1, 0, 0, x},
                {0, 1, 0, y},
                {0, 0, 1, z},
                {0, 0, 0, 1}
    });
}

obj3d::Matrix MatrixBuilder::scale(double x, double y, double z)
{
    return obj3d::Matrix({
                {x, 0, 0, 0},
                {0, y, 0, 0},
                {0, 0, z, 0},
                {0, 0, 0, 1}
    });
}
