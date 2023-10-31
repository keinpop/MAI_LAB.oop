#include "../header/square.h"

template <class T>
Square<T>::Square()
{
    DArray<T> points;
    this->_points = points;
    this->_name = "Square";
}

template <class T>
Square<T>::Square(const DArray<std::pair<T, T>> & points)
{
    if (points.getSize() != 4) {
        throw std::length_error("Error! Square Constructor: invalid number of coordinates");
    } else if (!checkValidPointsSquare(points)) {
        throw std::invalid_argument("Error! Square Constructor: invalid points");
    } else {
        this->_points = points;
        this->_name = "Square";
    }
}

template <class T>
Square<T>::~Square() noexcept
{
}

template <class T>
std::pair<T, T> Square<T>::calculateGeomCentr() const
{
    std::pair<T, T> tmp;

    for (size_t i = 0; i < this->_points.getSize(); ++i) {
        tmp.first += this->_points[i].first;
        tmp.second += this->_points[i].second;
    }

    tmp.first /= this->_points.getSize();
    tmp.second /= this->_points.getSize();

    return tmp;
}

template <class T> 
Square<T>::operator double() const // Calculate area of Square
{
    return pow(this->calculateLengthOfSide(), 2); 
}

template <class T>
bool Square<T>::checkValidPointsSquare(const DArray<std::pair<T, T>> & points)
{
    bool allSidesEqual = true;

    for (int i = 0; i < 4; i++) {
        int nextIndex = (i + 1) % 4;
        
        double sideLength1 = (sqrt(pow(points[nextIndex].first - points[i].first, 2) +
                                 pow(points[nextIndex].second - points[i].second, 2)));
        double sideLength2 = (sqrt(pow(points[(nextIndex + 1) % 4].first - points[nextIndex].first, 2) +
                                 pow(points[(nextIndex + 1) % 4].second - points[nextIndex].second, 2)));

        double angle1 = atan2(points[nextIndex].second - points[i].second,
                                 points[nextIndex].first - points[i].first);
        double angle2 = atan2(points[(nextIndex + 1) % 4].second - points[nextIndex].second,
                                 points[(nextIndex + 1) % 4].first - points[nextIndex].first);

        if ((!(abs(sideLength2 - sideLength1) < EPS)) && (!(fabs(angle1 - angle2) < EPS))) {
            allSidesEqual = false;
            break;
        }

    }

    return allSidesEqual ;
}