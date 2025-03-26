#ifndef MATRIX_H
#define MATRIX_H

#include "logic/math/point.h"

#include <initializer_list>

namespace obj3d {class Matrix;}

class obj3d::Matrix
{
public:
    constexpr static int size = 4;

private:
    double values[size][size];
    void set(const Matrix& other);

public:
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<double>> list);

    void set(int row, int column, double val);
    double get(int row, int column) const;

    obj3d::Point transform(const obj3d::Point& point) const;
    obj3d::Matrix& operator*=(const obj3d::Matrix& other);
};

obj3d::Matrix operator*(const obj3d::Matrix& a, const obj3d::Matrix& b);

#endif // MATRIX_H
