#pragma once

#include <iostream>
#include <cstdint>
#include <deque>

template <typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Allocator();

    ~Allocator();

    pointer allocate(size_type n);
    void deallocate(pointer ptr, size_type n);
    void free();

    template <class U>
    struct rebind 
    {
        using other = Allocator<U>;
    };

    template <typename... Args>
    void construct(pointer p, Args&&... args);

    void destroy(pointer ptr);

private:
    std::deque<T*> _used_blocks;
    std::deque<T*> _free_blocks;
};

template <typename T>
template <typename... Args>
void Allocator<T>::construct(pointer p, Args&&... args)
{
    new (p) T(std::forward<Args>(args)...);
}

template <typename T>
Allocator<T>::Allocator() {}

template <typename T>
Allocator<T>::~Allocator() 
{   
    this->free();
}

template <typename T>
T* Allocator<T>::allocate(size_type n)
{
    if (!_free_blocks.empty() && n == 1) { 
        T* tmp = _free_blocks.front();
        _free_blocks.pop_front(); 
        return tmp;
    }
    T* ptr = (T*)(::operator new(sizeof(T) * n));
    _used_blocks.push_back(ptr);

    return ptr;
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr, size_type n)
{
    if (_free_blocks.size() > _used_blocks.size()) {
        throw std::length_error("Error! deallocate: you want to delete unallocated blocks");
    }

    for (size_t j = 0; j < n; ++j) {
        _free_blocks.push_back(ptr + j * sizeof(T)); 
    }
}

template <typename T>
void Allocator<T>::free()
{
    size_t n = _used_blocks.size();
    for (size_t i = 0; i < n; ++i) {
        T* tmp = _used_blocks.front();
        _used_blocks.pop_front();
        delete(tmp);
    }
}

template <typename T>
void Allocator<T>::destroy(pointer ptr)
{
    ptr->~T();
}
