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
        std::vector<Coord> points;
        Coord tmp;
        int numbOfTop = 4;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            points.push_back(tmp);
        }

        if (sq.checkValidPointsSquare(points)) {
            sq._points = points;
        } else {
            throw std::range_error("Error! Square Constructor: invalid points");
        }
    }

    return stream;
}

Square::operator double() const // Calculate area of Square
{
    return pow(this->calculateLengthOfSide(), 2); 
}

void Square::operator=(const Square & other)
{
    if (other._points.size() < this->_points.size()) {
        this->_points = std::vector<Coord> (other._points.size());
    } else {
        this->_points = other._points;
    }

    this->_points = other._points;
}

bool Square::operator==(const Square & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;       
    }

    return true;
}

bool Square::checkValidPointsSquare(const std::vector<Coord> & points)
{
    bool allSidesEqual = true;

    for (int i = 0; i < 4; i++) {
        int nextIndex = (i + 1) % 4;
        double sideLength1 = round(sqrt(pow(points[nextIndex].x - points[i].x, 2) +
                                 pow(points[nextIndex].y - points[i].y, 2)));
        double sideLength2 = round(sqrt(pow(points[(nextIndex + 1) % 4].x - points[nextIndex].x, 2) +
                                 pow(points[(nextIndex + 1) % 4].y - points[nextIndex].y, 2)));
        
        if ((round(sideLength1) != round(sideLength2)) &&
            ((sideLength1 - sideLength2 < EPS) ||
            (sideLength2 - sideLength1 < EPS))) {
                
            allSidesEqual = false;
            break; 
        }
    }

    return allSidesEqual;
}


double Square::calculateLengthOfSide() const
{
    return sqrt(pow(_points[1].x - _points[0].x, 2) + 
            pow(_points[1].y - _points[0].y, 2));
}