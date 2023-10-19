#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "figure.h"

class Triangle final : public Figure
{
public:
    Triangle() = default;
    Triangle(const std::vector<Coord> & points);
    Triangle(const Triangle & other) noexcept = default;
    Triangle(Triangle && other) noexcept = default;

    virtual ~Triangle() noexcept;

    friend std::istream & operator>>(std::istream & stream, Triangle & tr);

    operator double() const;

    void operator=(const Triangle & other);

    bool operator==(const Triangle & other) const; 

private:
    bool checkValidPointsTriangle(const std::vector<Coord> & points);
    double calculateLengthOfSide() const;
};

#endif //__TRIANGLE_H__