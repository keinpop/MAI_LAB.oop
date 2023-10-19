#include "../header/figure.h"

Figure::Figure()
{
    std::vector<Coord> points;
    _points = points;
}

Figure::Figure(const std::vector<Coord> & points) 
{
    _points = points;
}

Figure::Figure(const Figure & other) noexcept
{
    _points = other._points;
}

Figure::Figure(Figure && other) noexcept
{
    std::swap(_points, other._points);
}

Figure::~Figure() noexcept
{   
}

Coord Figure::calculateGeomCentr() const
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

std::ostream & operator<<(std::ostream & stream, Coord coord)
{
    stream << "Ox: " << coord.x << " ";
    stream << "Oy: " << coord.y << std::endl;

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const Figure & fig)
{
    if (fig._points.size() == 0) {
        return stream << 0;
    }

    for (size_t i = 0; i < fig._points.size(); ++i) {
        stream << "Point " << i + 1 << "| ";
        stream << fig._points[i];
        
    }

    return stream;
}

std::istream & operator>>(std::istream & stream, Figure & fig)
{
    Coord tmp;
    std::cout << "Enter Ox: ";
    stream >> tmp.x;
    std::cout << "Enter Oy: ";
    stream >> tmp.y;
    
    fig._points.push_back(tmp);    

    return stream;
}


Figure::operator double() const
{
    return 0.0;
}

void Figure::operator=(const Figure & other)
{
    if (other._points.size() > this->_points.size()) {
        this->_points.resize(other._points.size());
    } else if (other._points.size() < this->_points.size()) {
        this->_points = std::vector<Coord> (other._points.size());
    }

    this->_points = other._points;
}

void Figure::operator=(Figure && other)
{
    std::swap(_points, other._points);
}
