#pragma once

#include "./allocator.h"
#include "./node.h"
#include "./iterator_FL.h"

#include <initializer_list>
#include <ostream>

template <typename T, class Allocator = Allocator<Node<T>>> 
class Forward_List
{
public:
    Forward_List();
    Forward_List(const T & value, size_t n);
    Forward_List(const std::initializer_list<T> & value);
    Forward_List(const Forward_List & other);
    Forward_List(Forward_List && other);

    ~Forward_List();
    
    size_t size() const;
    bool empty() const;

    void pushFront(const T & val);
    template<typename... Args>
    void emplaceFront(const T & first, const Args &...args);

    void popFront();

    void clear() noexcept;

    Iterator<T> begin() const;
    Iterator<T> end() const;
    ConstIterator<T> CBegin() const;
    ConstIterator<T> CEnd() const;
    
    template<typename U>
    friend std::ostream & operator<<(std::ostream & stream, const Forward_List<U> & l);

private:
    Allocator _alloc;
    Node<T>* _head = nullptr;
    size_t _size = 0;
};

template <typename T, class Allocator> 
Forward_List<T, Allocator>::Forward_List() :
    _head(nullptr), _size(0) {}

template <typename T, class Allocator> 
Forward_List<T, Allocator>::Forward_List(const T & value, size_t n)
{
    Node<T>* ptr = _alloc.allocate(1);
    ptr->setValue(value);
    this->_head = ptr;

    for (size_t i = 1; i < n; ++i) {
        ptr = _alloc.allocate(1);
        ptr->setValue(value);
        ptr->setNext(this->_head);
        _head = ptr;
    }

    _size = n;
}

template <typename T, class Allocator>
Forward_List<T, Allocator>::Forward_List(const std::initializer_list<T> & value)
{
    auto it = value.begin();
    _head = _alloc.allocate(1);
    _head->setValue(*it);
    Node<T>* ptr = _head;
    Node<T>* tmp;
    
    ++it;
    for (size_t i = 1; i < value.size(); ++i) {
        tmp = _alloc.allocate(1);
        tmp->setValue(*it);
        ptr->setNext(tmp);
        ptr = ptr->getNext();
        ++it;
    }

    _size = value.size();
}

template <typename T, class Allocator>
Forward_List<T, Allocator>::Forward_List(const Forward_List & other)
{
    Node<T>* ptr = _alloc.allocate(1);
    ptr = other._head;
    this->_head = ptr;

    Node<T>* tmp = other._head;
    tmp = tmp->getNext();

    for (size_t i = 1; i < other.size(); ++i) {
        ptr = ptr->getNext();
        ptr = _alloc.allocate(1);
        ptr = other._head;
        tmp = tmp->getNext();
    }

    _size = other.size();
}

template <typename T, class Allocator>
Forward_List<T, Allocator>::Forward_List(Forward_List && other)
{
    Node<T>* ptr = _alloc.allocate(1);
    ptr = other._head;
    this->_head = ptr;

    Node<T>* tmp = other._head;
    tmp = tmp->getNext();

    for (size_t i = 1; i < other.size(); ++i) {
        ptr = ptr->getNext();
        ptr = _alloc.allocate(1);
        ptr = other._head;
        tmp = tmp->getNext();
    }

    _size = other.size();
}

template<typename T, typename Allocator>
Forward_List<T, Allocator>::~Forward_List()
{
    _alloc.free();
}

template <typename T, class Allocator>
size_t Forward_List<T, Allocator>::size() const
{
    return this->_size;
}

template <typename T, class Allocator>
bool Forward_List<T, Allocator>::empty() const
{
    return (this->_size == 0);
}

template<typename T, typename Allocator>
void Forward_List<T, Allocator>::pushFront(const T & val)
{
    emplaceFront(val);
}

template<typename T, typename Allocator>
template<typename... Args>
void Forward_List<T, Allocator>::emplaceFront(const T & fValue, const Args &...args)
{
    Node<T>* ptr = _alloc.allocate(1);
    ptr->setValue(fValue);
    if (this->empty()) {
        _head = ptr;
        ++_size;

        if constexpr (sizeof...(args) > 0) {
            emplaceFront(args...);
        } else {
            return;
        }
    } else {
        ptr->setNext(_head);
        _head = ptr;
        ++_size;
        
        if constexpr (sizeof...(args) > 0) {
            emplaceFront(args...);
        }
    }
}

template<typename T, typename Allocator>
void Forward_List<T, Allocator>::popFront()
{
    if (this->empty()) {
        throw std::length_error("Error! Forward_List popFront: list empty");
    }

    Node<T>* delNode = _head;

    if (this->size() > 1) {
        _head = _head->getNext();
    } else {
        _head = nullptr;
    }

    _alloc.deallocate(delNode, 1);
    --_size;
}

template<typename T, typename Allocator>
void Forward_List<T, Allocator>::clear() noexcept
{
    size_t size = this->size();
    for (size_t i = 0; i < size; ++i) {
        this->popFront();
    }
}

template<typename T, typename Allocator>
Iterator<T> Forward_List<T, Allocator>::begin() const
{
    Iterator<T> begin(_head);
    return begin;
}

template<typename T, typename Allocator>
Iterator<T> Forward_List<T, Allocator>::end() const
{
    return (this->begin() + (this->size()));
}

template<typename T, typename Allocator>
ConstIterator<T> Forward_List<T, Allocator>::CBegin() const
{
    ConstIterator<T> begin(_head);
    return begin;
}

template<typename T, typename Allocator>
ConstIterator<T> Forward_List<T, Allocator>::CEnd() const
{
    return (this->CBegin() + (this->size()));
}

template<typename U>
std::ostream & operator<<(std::ostream & stream, const Forward_List<U> & l)
{
    if (l.empty()) {
        throw std::length_error("Error! Forward_List operator<<: list empty");
    }

    size_t size = l.size();
    Node<U>* tmp = l._head;
    for (size_t i = 0; i < size; ++i) {
        stream << tmp->getValue() << '\t';
        tmp = tmp->getNext();
    }

    stream << '\n';

    return stream;
}