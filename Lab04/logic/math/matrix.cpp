#include "logic/math/matrix.h"
#include "logic/exceptions/incorrectindexexception.h"
#include "logic/exceptions/incorrectsize.h"

obj3d::Matrix::Matrix()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->values[i][j] = 0;
        }
    }
}

obj3d::Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list)
{
    if (list.size() != size)
    {
        throw IncorrectSize();
    }
    int i = 0;
    for (std::initializer_list<double> row : list)
    {
        if (row.size() != size)
        {
            throw IncorrectSize();
        }
        int j = 0;
        for (double cell : row)
        {
            values[i][j] = cell;
            j++;
        }
        i++;
    }
}

void obj3d::Matrix::set(const obj3d::Matrix& other)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->values[i][j] = other.values[i][j];
        }
    }
}

void obj3d::Matrix::set(int row, int column, double val)
{
    if (row >= size || column >= size)
    {
        throw IncorrectIndex();
    }
    this->values[row][column] = val;
}

double obj3d::Matrix::get(int row, int column) const
{
    if (row >= size || column || size)
    {
        throw IncorrectIndex();
    }
    return this->values[row][column];
}

obj3d::Matrix& obj3d::Matrix::operator*=(const obj3d::Matrix& other)
{
    obj3d::Matrix result;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                result.values[i][j] += values[i][k] * other.values[k][j];
            }
        }
    }
    set(result);
    return *this;
}

obj3d::Matrix operator*(const obj3d::Matrix& a, const obj3d::Matrix& b)
{
    obj3d::Matrix result = a;
    result *= b;
    return result;
}

obj3d::Point obj3d::Matrix::transform(const obj3d::Point& point) const
{
    double vector[size] = {point.X(),  point.Y(), point.Z(), 1};
    double result[size] = {};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i] += values[i][j] * vector[j];
        }
    }
    return obj3d::Point(result[0], result[1], result[2]);
}
