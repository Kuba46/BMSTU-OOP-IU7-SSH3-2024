#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../Iterators/Iterator.h"

template <typename T>
Iterator<T>::Iterator(std::shared_ptr<T[]> ptr, int pos)
{
	this->ptr = ptr;
	this->pos = pos;
}

template <typename T>
Iterator<T>& Iterator<T>::next()
{
    ++pos;
    return *this;
}

template <typename T>
T& Iterator<T>::value() 
{
    return ptr[pos];
}

template <typename T>
bool Iterator<T>::isEnd() const 
{
    return pos == length;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
    ++pos;
    return *this;
}

template <typename T>
T& Iterator<T>::operator*()
{
    return ptr[pos];
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& iterator) const
{
    return ptr == iterator.ptr && pos == iterator.pos;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& iterator) const
{
    return !(*this == iterator);
}

#endif // !ITERATOR_HPP
