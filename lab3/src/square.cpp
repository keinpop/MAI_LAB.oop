#include "../header/square.h"

Square::Square(const std::vector<Coord> & points)
{
    if (points.size() != 4) {
        throw std::range_error("Error! Square Constructor: invalid number of coordinates");
    } else if (!checkValidPointsSquare(points)){
        throw std::range_error("Error! Square Constructor: invalid points");
    } else {
        _points = points;
    }
}

Square::~Square() noexcept
{
}

std::istream & operator>>(std::istream & stream, Square & sq)
{
    if (sq._points.size() != 0) {
        throw std::range_error("Error! operator>>: this Square already has points");
    } else {
        Coord tmp;
        int numbOfTop = 4;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            sq._points.push_back(tmp);
        }
    }

    return stream;
}

Square::operator double() const // Calculate area of Square
{
    return this->calculateLengthOfSide() * this->calculateLengthOfSide(); 
}

void Square::operator=(const Square & other)
{
    if (other._points.size() > this->_points.size()) {
        this->_points.resize(other._points.size());
    } else if (other._points.size() < this->_points.size()) {
        this->_points = std::vector<Coord> (other._points.size());
    }

    this->_points = other._points;
}

void Square::operator=(Square && other)
{
    std::swap(_points, other._points);
}

bool Square::operator==(const Square & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;       
    }

    return true;
}

double Square::calculateLengthOfHypotenuse(const Coord & p1, const Coord & p2) const
{   
    return sqrt(pow(p1.x, 2) + pow(p2.x, 2)); 
}

bool Square::checkValidPointsSquare(const std::vector<Coord> & points)
{
    if (calculateLengthOfHypotenuse(points[0], points[2]) == calculateLengthOfHypotenuse(points[1], points[3]) &&
        calculateLengthOfHypotenuse(points[2], points[0]) == calculateLengthOfHypotenuse(points[3], points[1])) {
        
        return true;
    }

    return false;
}

double Square::calculateLengthOfSide() const
{
    if (this->_points[0].x == this->_points[1].x) {
        return _points[1].y - _points[0].y;
    } else if (this->_points[0].y == this->_points[1].y) {
        return _points[1].x - _points[0].x;
    }

    return 0;
}