#pragma once

template <typename T>
class Node
{
public:
    Node() = default;
    explicit Node(const T & val, Node<T>* next);
    ~Node() = default;

private:
    T _value;
    Node* _next;
};

template <typename T>
Node<T>::Node(const T & val, Node<T>* next)
{
    this->next = next;
    this->_value = val;
}