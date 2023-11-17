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

    Iterator<T> &operator++();
    Iterator<T> &operator+(int64_t num);

    const T & operator*() const;
    T operator->() const;
    
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
Iterator<T> &Iterator<T>::operator++()
{
    if (_node) {
        _node = _node->getNext();
    }

    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator+(int64_t num)
{
    if (num > 0) {
        while (num && _node) {
            _node = _node->getNext();
            --num;
        }
    }

    return *this;
}

template <typename T>
const T & Iterator<T>::operator*() const
{
    return _node->getValue();
}

template <typename T>
T Iterator<T>::operator->() const
{
    return _node->getValue();
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
    explicit ConstIterator(const Node<T>* node);

    ~ConstIterator() = default;

    const Node<T>* getNode() const;

    const ConstIterator<T> &operator++();
    const ConstIterator<T> &operator+(int64_t num);

    const T & operator*() const;  
    const T & operator->() const;
    
    bool operator==(const ConstIterator<T> & other) const;
    bool operator!=(const ConstIterator<T> & other) const;
 
private:
    const Node<T>* _node;
};

template <typename T>
ConstIterator<T>::ConstIterator(const Node<T>* node)
{
    _node = node;
}

template <typename T>
const Node<T>* ConstIterator<T>::getNode() const 
{
    return this->_node;
}

template <typename T>
const ConstIterator<T> &ConstIterator<T>::operator++()
{
    if (_node) {
        _node = _node->getNext();
    }

    return *this;
}

template <typename T>
const ConstIterator<T> &ConstIterator<T>::operator+(int64_t num)
{
    if (num > 0) {
        while (num && _node) {
            _node = _node->getNext();
            --num;
        }
    }

    return *this;
}

template <typename T>
const T & ConstIterator<T>::operator*() const
{
    return _node->getValue();
}

template <typename T>
const T & ConstIterator<T>::operator->() const
{
    return _node->getValue();
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