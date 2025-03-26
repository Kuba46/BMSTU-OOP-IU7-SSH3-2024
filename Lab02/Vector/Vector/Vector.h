#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

#include "../Iterators/Iterator.h"
#include "../Exceptions/Exceptions.hpp"

#include <initializer_list>

template <typename T>
class Vector
{
public:
    Vector(int length);
    Vector(const Vector<T>& vect);
    Vector(Vector<T>&& vect) noexcept;
    Vector(std::initializer_list<T> lst);

    ~Vector() = default;

    Vector<T>& operator=(const Vector<T>& vect);

    int getLength() const;
    void setElem(int index, const T& elem);

    T& getElem(int index);
    T* toArray();

    T& operator[](int index);
    const T& operator[](int index) const;

    template<typename _T>
    friend std::ostream& operator<<(std::ostream& os, const Vector<_T>& lst)
    {
        for (int i = 0; i < lst.length; ++i)
        {
            os << lst.values[i] << " ";
        }
        return os;
    }

    Vector<T>& operator+=(const Vector<T>& vect);
    Vector<T>& operator-=(const Vector<T>& vect);
    Vector<T>& operator*=(const T& val);
    Vector<T>& operator/=(const T& val);

    Iterator<T> begin();
    Iterator<T> end();

private:
    int length;
    std::shared_ptr<T[]> values;
};

#include "../Vector/Vector.hpp"

#endif // VECTOR_H
