#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

#include "../Exceptions/Exceptions.hpp"

template<typename T>
class Vector;

template <typename T>
class Iterator 
{
public:
    Iterator(std::shared_ptr<T[]> ptr, int pos);
    Iterator<T>& next();

    T& value();
    bool isEnd() const;

    Iterator<T>& operator++();

    T& operator*();

    /*bool operator <=(const Iterator<T>& iterator) const;
    bool operator <(const Iterator<T>& iterator) const;
    bool operator >=(const Iterator<T>& iterator) const;
    bool operator >(const Iterator<T>& iterator) const;*/
    bool operator==(const Iterator<T>& iterator) const;
    bool operator!=(const Iterator<T>& iterator) const;

private:
    std::shared_ptr<T[]> ptr;
    int pos;
    int length;
};

#include "../Iterators/Iterator.hpp"

#endif // ITERATOR_H