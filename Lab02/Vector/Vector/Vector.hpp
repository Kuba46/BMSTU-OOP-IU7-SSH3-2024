#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Vector/Vector.h"

#include <iostream>
#include <cstdlib>
#include <memory>

template <typename T>
Vector<T>::Vector(int length)
{
	if (length <= 0)
	{
		throw EmptyVectorError(__FILE__, __LINE__);
	}
	this->length = length;
	this->values = std::make_shared<T[]>(length);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vect) : length(vect.length), values(std::make_shared<T[]>(vect.length))
{
    std::copy(vect.values.get(), vect.values.get() + vect.length, values.get());
}

template <typename T>
Vector<T>::Vector(Vector<T>&& vect) noexcept : length(vect.length), values(std::move(vect.values))
{
    vect.length = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst) : length(lst.size()), values(std::make_shared<T[]>(lst.size()))
{
    std::copy(lst.begin(), lst.end(), values.get());
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vect)
{
    if (this == &vect) return *this;
    length = vect.length;
    values = std::make_shared<T[]>(vect.length);
    std::copy(vect.values.get(), vect.values.get() + vect.length, values.get());
    return *this;
}

template <typename T>
int Vector<T>::getLength() const
{
    return length;
}

template <typename T>
void Vector<T>::setElem(int index, const T& elem)
{
    if (index < 0 || index >= length)
    {
        throw IndexVectorError(__FILE__, __LINE__);
    }
    values[index] = elem;
}

template <typename T>
T& Vector<T>::getElem(int index)
{
    if (index < 0 || index >= length)
    {
        throw IndexVectorError(__FILE__, __LINE__);
    }
    return values[index];
}

template <typename T>
T* Vector<T>::toArray()
{
	T* array = new T[length];
	if (!array)
	{
		throw InvalidCopyArrayPointer(__FILE__, __LINE__);
	}
    std::copy(values.get(), values.get() + length, array);
    return array;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index >= length)
    {
        throw IndexVectorError(__FILE__, __LINE__);
    }
    return values[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const
{
    if (index < 0 || index >= length)
    {
        throw IndexVectorError(__FILE__, __LINE__);
    }
    return values[index];
}

template <typename T>

Vector<T>& Vector<T>::operator+=(const Vector<T>& vect)
{
    if (length != vect.length)
    {
		throw DifferentSizeVectors(__FILE__, __LINE__);
    }
    for (int i = 0; i < length; ++i)
    {
        values[i] += vect.values[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& vect)
{
    if (length != vect.length)
    {
		throw DifferentSizeVectors(__FILE__, __LINE__);
    }
    for (int i = 0; i < length; ++i)
    {
        values[i] -= vect.values[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const T& val)
{
    for (int i = 0; i < length; ++i)
    {
        values[i] *= val;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator/=(const T& val)
{
    if (val == 0)
    {
		throw ZeroDivError(__FILE__, __LINE__);
    }
    for (int i = 0; i < length; ++i)
    {
        values[i] /= val;
    }
    return *this;
}

template <typename T>
Iterator<T> Vector<T>::begin()
{
    return Iterator<T>(values, 0);
}

template <typename T>
Iterator<T> Vector<T>::end() 
{
    return Iterator<T>(values, length);
}

template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
{
    if (v1.getLength() != v2.getLength())
    {
		throw DifferentSizeVectors(__FILE__, __LINE__);
    }
    Vector<T> result(v1.getLength());
    for (int i = 0; i < v1.getLength(); ++i)
    {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

template<typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) 
{
    if (v1.getLength() != v2.getLength())
    {
        throw DifferentSizeVectors(__FILE__, __LINE__);
    }
    Vector<T> result(v1.getLength());
    for (int i = 0; i < v1.getLength(); ++i)
    {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

template<typename T>
Vector<T> operator*(const Vector<T>& v1, const T& val) 
{
    Vector<T> result(v1.getLength());
    for (int i = 0; i < v1.getLength(); ++i)
    {
        result[i] = v1[i] * val;
    }
    return result;
}

template<typename T>
Vector<T> operator/(const Vector<T>& v1, const T& val) 
{
    if (val == 0)
    {
		throw ZeroDivError(__FILE__, __LINE__);
    }
    Vector<T> result(v1.getLength());
    for (int i = 0; i < v1.getLength(); ++i)
    {
        result[i] = v1[i] / val;
    }
    return result;
}

#endif // !VECTOR_HPP
