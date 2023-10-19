#include "../header/triangle.h"

Triangle::Triangle(const std::vector<Coord> & points)
{
    if (points.size() != 3) {
        throw std::range_error("Error! Triangle Constructor: invalid number of coordinates");
    } else if (!checkValidPointsTriangle(points)){
        throw std::range_error("Error! Triangle Constructor: invalid points");
    } else {
        _points = points;
    }
}

Triangle::~Triangle() noexcept
{
}

std::istream & operator>>(std::istream & stream, Triangle & tr)
{
    if (tr._points.size() != 0) {
        throw std::range_error("Error! operator>>: this Triangle already has points");
    } else {
        std::vector<Coord> points;
        Coord tmp;
        int numbOfTop = 3;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            points.push_back(tmp);
        }

        if (tr.checkValidPointsTriangle(points)) {
            tr._points = points;
        } else {
            throw std::range_error("Error! Triangle operator>>: invalid points");
        }
        
    }    

    return stream;
}

Triangle::operator double() const // Calculate area of Triangle
{
    double lenSide = this->calculateLengthOfSide();

    return ((pow(lenSide, 2) * sqrt(3)) / 4);
}

void Triangle::operator=(const Triangle & other)
{
    if (other._points.size() < this->_points.size()) {
        this->_points = std::vector<Coord> (other._points.size());
    } else {
        this->_points = other._points;
    }

    this->_points = other._points;
}

bool Triangle::operator==(const Triangle & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;
    }

    return true;
}

bool Triangle::checkValidPointsTriangle(const std::vector<Coord> & points)
{
    bool allSidesEqual = true; 

    for (size_t i = 0; i < points.size(); ++i) {
        int nextIndex = (i + 1) % 3;
        double sideLength1 = (sqrt(pow(points[nextIndex].x - points[i].x, 2) +
                                 pow(points[nextIndex].y - points[i].y, 2)));
        double sideLength2 = (sqrt(pow(points[(nextIndex + 1) % 3].x - points[nextIndex].x, 2) +
                                 pow(points[(nextIndex + 1) % 3].y - points[nextIndex].y, 2)));
        
        if ((round(sideLength1) != round(sideLength2)) &&
            ((sideLength1 - sideLength2 < EPS) ||
            (sideLength2 - sideLength1 < EPS))) {
                
            allSidesEqual = false; 
            break;
        }
    }

    return allSidesEqual;   
}

double Triangle::calculateLengthOfSide() const
{
    return sqrt(pow(this->_points[0].x - this->_points[1].x, 2) + 
        pow(this->_points[0].y - this->_points[1].y, 2));
}