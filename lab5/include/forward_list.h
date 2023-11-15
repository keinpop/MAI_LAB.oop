#pragma once

#include "./allocator.h"
#include "./node.h"
#include "./iterator_FL.h"

template <typename T, class Allocator = Allocator<T>> 
class Forward_List
{
public:


private:
    Allocator _alloc;
    Node<T>* _head;
    size_t _size = 0;
};
