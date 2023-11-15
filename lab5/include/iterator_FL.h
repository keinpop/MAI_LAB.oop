#pragma once

#include "./node.h"

#include <iostream>

template <typename T>
class Iterator
{
public:
    Iterator() = default;
    explicit Iterator(Node<T>* node);

    ~Iterator() = default;

    Node<T>* getNode() const;

    Iterator<T> operator++();
    Iterator<T> operator+(int64_t num);

    T & operator*();
    
    bool operator==(const Iterator<T> & other) const;
    bool operator!=(const Iterator<T> & other) const;
 
private:
    Node<T>* _node;
};

template <typename T>
Iterator<T>::Iterator(Node<T>* node)
{
    _node = node;
}

template <typename T>
Node<T>* Iterator<T>::getNode() const 
{
    return this->_node;
}

template <typename T>
Iterator<T> Iterator<T>::operator++()
{
    if (_node) {
        _node = _node->_next;
    }

    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(int64_t num)
{
    if (num > 0) {
        while (num && _node) {
            _node = _node->_next;
            --num;
        }
    }

    return *this;
}

template <typename T>
T & Iterator<T>::operator*()
{
    return _node->_value;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T> & other) const
{
    return this->_node == other._node;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> & other) const
{
    return !(*this == other);
}

template <typename T>
class ConstIterator
{
public:
    ConstIterator() = default;
    explicit ConstIterator(Node<T>* node);

    ~ConstIterator() = default;

    Node<T>* getNode() const;

    ConstIterator<T> operator++();
    ConstIterator<T> operator+(int64_t num);

    const T & operator*() const;  
    
    bool operator==(const ConstIterator<T> & other) const;
    bool operator!=(const ConstIterator<T> & other) const;
 
private:
    Node<T>* _node;
};

template <typename T>
ConstIterator<T>::ConstIterator(Node<T>* node)
{
    _node = node;
}

template <typename T>
Node<T>* ConstIterator<T>::getNode() const 
{
    return this->_node;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator++()
{
    if (_node) {
        _node = _node->_next;
    }

    return *this;
}

template <typename T>
ConstIterator<T> ConstIterator<T>::operator+(int64_t num)
{
    if (num > 0) {
        while (num && _node) {
            _node = _node->_next;
            --num;
        }
    }

    return *this;
}

template <typename T>
const T & ConstIterator<T>::operator*() const
{
    return _node->_value;
}

template <typename T>
bool ConstIterator<T>::operator==(const ConstIterator<T> & other) const
{
    return this->_node == other._node;
}

template <typename T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> & other) const
{
    return !(*this == other);
}