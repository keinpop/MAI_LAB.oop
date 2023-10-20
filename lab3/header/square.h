#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "figure.h"

class Square final : public Figure
{
public:
    Square() = default;
    Square(const std::vector<Coord> & points);
    Square(const Square & other) noexcept;
    Square(Square && other) noexcept;

    virtual ~Square() noexcept;

    friend std::istream & operator>>(std::istream & stream, Square & sq);
    
    Coord calculateGeomCentr() const override;
    operator double() const override;
    
    void operator=(const Square & other);

    bool operator==(const Square & other) const;

private:
    bool checkValidPointsSquare(const std::vector<Coord> & points);
};

#endif // __SQUARE_H__