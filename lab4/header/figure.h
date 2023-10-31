#pragma once

#include <ostream>

#include "./dynamicArray.h"

template <class T>
class Figure
{
public:
    Figure();
    Figure(const DArray<std::pair<T, T>> & points);
    Figure(const std::initializer_list<std::pair<T, T>> & coord);

    ~Figure() noexcept;

    friend std::ostream & operator<<(std::ostream & stream, std::pair<T, T> coord);

protected:
    DArray<std::pair<T, T>> _points;
    std::string _name = "unnamed";
};

#include "../src/figure.cpp"