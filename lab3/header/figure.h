#ifndef __FIGURE_H__
#define __FIGURE_H__

#include <iostream>
#include <vector>
#include <ostream>
#include <cmath>

#define EPS pow(10, -3)

typedef struct _coordinates {
    double x;
    double y;
} Coord;

class Figure
{
public:
    Figure();
    Figure(const std::vector<Coord> & points);
    Figure(const Figure & other) noexcept;
    Figure(Figure&& other) noexcept;

    ~Figure() noexcept;

    Coord calculateGeomCentr() const;
    friend std::ostream & operator<<(std::ostream & stream, Coord coord);
    friend std::ostream & operator<<(std::ostream & stream, const Figure & fig);
    friend std::istream & operator>>(std::istream & stream, Figure & fig);
    
    virtual operator double() const;

    void operator=(const Figure & other);
    void operator=(Figure && other);

protected:
    std::vector<Coord> _points;
};

#endif // __FIGURE_H__