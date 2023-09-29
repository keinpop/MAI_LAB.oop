#include "../header/seven.h"

Seven::Seven() : _size(0), _array{nullptr}
{
    std::cout << "Default constructor" << std::endl;
}

Seven::Seven(const size_t & n, unsigned char elem)
{
    std::cout << "Fill constructor zeros" << std::endl;
    _array = new unsigned char[n];

    for (int i = 0; i < n; i++) {
        _array[i] = elem;
    }

    _size = n;
}

Seven::Seven(const std::initializer_list<unsigned char> &array)
{
    std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[array.size()];
    size_t i{0};
    for (auto c : array) 
        _array[i++] = c;
}

Seven::Seven(const std::string &t)
{
    std::cout << "Copy string constructor" << std::endl;
    _array =  new unsigned char[t.size()];
    _size = t.size();
    
    for (int i = 0; i < _size; i++) 
        _array[i] = t[i]; 
}

Seven::Seven(Seven&& other) noexcept 
{  
    std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _array = other._array;

    other._array = nullptr; // NULL
    other._size = 0;
}

Seven::~Seven() noexcept
{
    _size = 0;
    delete[] _array;
    _array = nullptr;
}