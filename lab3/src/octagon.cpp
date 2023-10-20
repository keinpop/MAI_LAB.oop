#include "../header/octagon.h"

Octagon::Octagon()
{
    std::vector<Coord> points;
    _points = points;
    _name = "Octagon";
}

Octagon::Octagon(const std::vector<Coord> & points)
{
    if (points.size() != 8) {
        throw std::range_error("Error! Octagon Constructor: invalid number of coordinates");
    } else if (!checkValidPointsOctagon(points)){
        throw std::range_error("Error! Octagon Constructor: invalid points");
    } else {
        _points = points;
        _name = "Octagon";
    }
}

Octagon::Octagon(const Octagon & other) noexcept
{
    _points = other._points;
    _name = "Octagon";
}

Octagon::Octagon(Octagon && other) noexcept
{
    std::swap(_points, other._points);
    other._name = "Octagon";
}

Octagon::~Octagon() noexcept
{
}

std::istream & operator>>(std::istream & stream, Octagon & oc)
{
    if (oc._points.size() != 0) {
        throw std::range_error("Error! operator>>: this Octagon already has points");
    } else {
        std::vector<Coord> points;
        Coord tmp;
        int numbOfTop = 8;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            points.push_back(tmp);
        }

        if (oc.checkValidPointsOctagon(points)) {
            oc._points = points;
        } else {
            throw std::range_error("Error! Octagon Constructor: invalid points");
        }
    }

    return stream;
}

Coord Octagon::calculateGeomCentr() const
{
    Coord tmp;

    for (size_t i = 0; i < _points.size(); ++i) {
        tmp.x += _points[i].x;
        tmp.y += _points[i].y;
    }

    tmp.x /= _points.size();
    tmp.y /= _points.size();

    return tmp;
}

Octagon::operator double() const // Calculate area of Octagon
{
    double lenSide = this->calculateLengthOfSide();

    return (2 * pow(lenSide, 2) * (1 + sqrt(2)));
}

void Octagon::operator=(const Octagon & other)
{
    if (other._points.size() < this->_points.size()) {
        this->_points = std::vector<Coord> (other._points.size());
    } else {
        this->_points = other._points;
    }

    this->_points = other._points;
}

bool Octagon::operator==(const Octagon & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;       
    }

    return true;
}

bool Octagon::checkValidPointsOctagon(const std::vector<Coord> & points)
{
    bool allSidesEqual = true; 

    for (size_t i = 0; i < points.size(); ++i) {
        int nextIndex = (i + 1) % 8;
        double sideLength1 = (sqrt(pow(points[nextIndex].x - points[i].x, 2) +
                                 pow(points[nextIndex].y - points[i].y, 2)));
        double sideLength2 = (sqrt(pow(points[(nextIndex + 1) % 8].x - points[nextIndex].x, 2) +
                                 pow(points[(nextIndex + 1) % 8].y - points[nextIndex].y, 2)));
        
        if ((round(sideLength1) != round(sideLength2)) &&
            ((abs(sideLength1 - sideLength2) < EPS) ||
            (abs(sideLength2 - sideLength1) < EPS))) {

            allSidesEqual = false; 
            break;
        }
    }

    return allSidesEqual;
}
