#ifndef __OCTAGON_H__
#define __OCTAGON_H__

#include "figure.h"

class Octagon final : public Figure
{
public:
    Octagon() = default;
    Octagon(const std::vector<Coord> & points);
    Octagon(const Octagon & other) noexcept = default;
    Octagon(Octagon && other) noexcept = default;

    virtual ~Octagon() noexcept;

    friend std::istream & operator>>(std::istream & stream, Octagon & sq);

    operator double() const;

    void operator=(const Octagon & other);

    bool operator==(const Octagon & other) const;

private:
    bool checkValidPointsOctagon(const std::vector<Coord> & points);
    double calculateLengthOfSide() const;

};

#endif // __OCTAGON_H__