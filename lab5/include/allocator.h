#pragma once

#include <iostream>
#include <cstdint>
#include <stack>

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
    void construct(pointer p, Args&& ...args);

    void destroy(pointer ptr);

private:
    std::stack<T* > _used_blocks;
    std::stack<T* > _free_blocks;
};

template <typename T>
template <typename... Args>
void Allocator<T>::construct(pointer p, Args&& ...args)
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
    if (_free_blocks.size() != 0 && n == 1) { 
        T* tmp = _free_blocks.top();
        _free_blocks.pop(); 
        return tmp;
    }
    T* ptr = (T*)(::operator new(sizeof(T) * n));
    _used_blocks.push(ptr);

    return ptr;
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr, size_type n)
{
    for (size_t j = 0; j < n; ++j) {
        _free_blocks.push(ptr + j * sizeof(T)); 
    }
}

template <typename T>
void Allocator<T>::free()
{
    std::cout << "Size _used_blocks = " << _used_blocks.size() << '\n';
    for (size_t i = 0 ; i < _used_blocks.size() ; ++i) {
        T* tmp = _used_blocks.top();
        _used_blocks.pop();
        delete tmp;
    }
}

template <typename T>
void Allocator<T>::destroy(pointer ptr)
{
    ptr->~T();
}