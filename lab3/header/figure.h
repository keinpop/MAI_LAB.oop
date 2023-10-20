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

    ~Figure() noexcept;

    friend std::ostream & operator<<(std::ostream & stream, const Figure & fig);
    friend std::istream & operator>>(std::istream & stream, Figure & fig);
    
    virtual Coord calculateGeomCentr() const = 0;
    
    virtual operator double() const = 0;

    void operator=(const Figure & other);
    void operator=(Figure && other);

    virtual double calculateLengthOfSide() const;
    const std::string getNameFigure() const;
protected:
    std::vector<Coord> _points;
    std::string _name = "unnamed";
};

#endif // __FIGURE_H__