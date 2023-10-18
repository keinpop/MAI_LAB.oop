#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "figure.h"
#include <cmath>

class Square final : public Figure
{
public:
    Square() = default;
    Square(const std::vector<Coord> & points);
    Square(const Square & other) noexcept = default;
    Square(Square && other) noexcept = default;

    virtual ~Square() noexcept;

    friend std::istream & operator>>(std::istream & stream, Square & sq);
    
    operator double() const;
    
    void operator=(const Square & other);
    void operator=(Square && other);

    bool operator==(const Square & other) const;

private:
    double calculateLengthOfHypotenuse(const Coord & p1, const Coord & p2) const;
    bool checkValidPointsSquare(const std::vector<Coord> & points);
    double calculateLengthOfSide() const;
};

#endif // __SQUARE_H__