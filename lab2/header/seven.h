#pragma once 

#include <iostream>
#include <string>

class Seven
{
public:
    Seven();
    Seven(const size_t & n, unsigned char elem = 0);
    Seven(const std::initializer_list<unsigned char> &array);
    Seven(const std::string &t);
    Seven(Seven&& other) noexcept;

    virtual ~Seven() noexcept;
private:
    size_t _size;
    unsigned char *_array;
};