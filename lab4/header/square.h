#pragma once

#include "./figure.h"

template <class T>
class Square final : public Figure<T>
{
public:
    Square();
    Square(const DArray<std::pair<T, T>> & points);

    ~Square() noexcept;

    std::pair<T, T> calculateGeomCentr() const override;
    operator double() const override;

private:
    bool checkValidPointsSquare(const DArray<std::pair<T, T>> & points);
};

#include "../src/square.cpp"