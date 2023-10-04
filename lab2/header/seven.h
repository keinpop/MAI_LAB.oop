#pragma once 

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <ostream>

class Seven
{
public:
    Seven();
    Seven(const size_t & n, unsigned char elem = 0);
    Seven(const std::initializer_list<unsigned char> & str);
    Seven(const Seven &other);
    Seven(const std::string & other);
    Seven(Seven&& other) noexcept;

    virtual ~Seven() noexcept;

    size_t getSize() const;
    unsigned char getArrayElem(size_t iter);
    void setArrayElem(size_t iter, unsigned char value);
    void resizeArrayPlus();
    void resizeArrayMinus();

    unsigned char & operator[](size_t index);
    
    bool operator>(const Seven & other) const;
    bool operator>=(const Seven & other) const;
    bool operator<(const Seven & other) const;
    bool operator<=(const Seven & other) const;
    bool operator==(const Seven & other) const;
    bool operator!=(const Seven & other) const;

    friend std::ostream & operator<<(std::ostream &stream, const Seven & seven);
    friend std::istream & operator>>(std::istream & stream, Seven & seven);
    
    void operator=(Seven & other);
    Seven operator+(const Seven & other) const;
    Seven operator-(const Seven & other) const;

    Seven operator+=(const Seven & other);
    Seven operator-=(const Seven & other);

private:
    size_t _size;
    unsigned char *_array;
};