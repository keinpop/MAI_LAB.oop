#pragma once

#include <initializer_list>
#include <limits>
#include <cstring>
#include <algorithm>
#include <iostream>

template <class T>
class DArray 
{
public:
    DArray();
    DArray(const std::initializer_list<T> & coord);
    DArray(const DArray & other);
    DArray(DArray&& other) noexcept;

    ~DArray() noexcept;

    void pushBack(const T & figure);
    void deleteToIndex(size_t index);

    T & operator[](size_t index) const;

    size_t getSize() const;

    void operator=(const DArray & other);
    void operator=(DArray&& other);
    

private:
    void realocate(const size_t minSize);
    size_t calculateCapacity(const size_t minSize);

private:
    size_t _size = 0;
    size_t _capacity = 0;
    T* _array = nullptr;
};

#include "../src/dynamicArray.cpp"