#include "../header/figure.h"

template <class T>
Figure<T>::Figure() :
    _points() {}

template <class T>
Figure<T>::Figure(const DArray<std::pair<T, T>> & points) :
    _points(points) {}

template <class T>
Figure<T>::Figure(const std::initializer_list<std::pair<T, T>> & coord) : 
    _points(coord) {}

template <class T>
Figure<T>::~Figure() noexcept
{
}

template <class T>
std::ostream & operator<<(std::ostream & stream, std::pair<T, T> coord)
{
    
    return stream;
}
