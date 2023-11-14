#pragma once

#include <iostream>
#include <cstdint>
#include <stack>

template <typename T>
class Allocator
{
public:
    Allocator();

    ~Allocator();

    T* allocate(size_t n);
    void deallocate(T* ptr, size_t n);
    void free();

    template <class U>
    struct rebind 
    {
        using other = Allocator<U>;
    };

    template <typename... Args>
    void construct(T* p, Args&& ...args);

    void destroy(T* ptr);

private:
    std::stack<T* > _used_blocks;
    std::stack<T* > _free_blocks;
};

template <typename T>
template <typename... Args>
void Allocator<T>::construct(T* p, Args&& ...args)
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
T* Allocator<T>::allocate(size_t n)
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
void Allocator<T>::deallocate(T* ptr, size_t n)
{
    for (size_t j = 0; j < n; ++j) {
        _free_blocks.push(ptr + j * sizeof(T)); 
    }
}

template <typename T>
void Allocator<T>::free()
{
    for (size_t i = 0 ; i < _used_blocks.size() ; ++i) {
        T* tmp = _used_blocks.top();
        _used_blocks.pop();
        delete tmp;
    }
}

template <typename T>
void Allocator<T>::destroy(T* ptr)
{
    ptr->~T();
}