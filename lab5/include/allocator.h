#pragma once

#include <iostream>
#include <cstdint>
#include <stack>

template <typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = size_t;

    Allocator();

    //~Allocator();

    T* allocate(size_t n);
    void deallocate(T* ptr, size_t n);

private:
    std::stack<T*> _used_blocks;
    std::stack<void* > _free_blocks;
    size_t _alloc_count;
};

template <typename T>
Allocator<T>::Allocator() : 
    _alloc_count(0) {}

template <typename T>
T* Allocator<T>::allocate(size_t n)
{
    T* ptr = (T*)(::operator new(sizeof(T) * n));
    _used_blocks.push(ptr);

    for (size_t i = _alloc_count; i < _alloc_count + n; ++i) {
        _free_blocks.push(ptr + i * sizeof(T));
    }

    _alloc_count += n;
    
    return ptr;
}

template <typename T>
void Allocator<T>::deallocate(T* ptr, size_t n)
{
    std::stack<void* > tmp;

    for (long long i = 0; i > _alloc_count - n; --i) {
        tmp.push(_free_blocks.top());
        _free_blocks.pop();
    }

    void* delEl = _free_blocks.top();
    delete delEl;

    for (size_t j = 0; j < n; ++j) {
        _free_blocks.push(tmp.pop());
    }
}