#pragma once

template <typename T>
class Node
{
public:
    Node() = default;
    explicit Node(const T & val, Node<T>* next);
    ~Node() = default;
    
    const T & getValue() const;
    void setValue(const T & val);

    Node* getNext() const;
    void setNext(Node* ptr);

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

template <typename T>
const T & Node<T>::getValue() const
{
    return this->_value;
}

template <typename T>
void Node<T>::setValue(const T & val)
{
    this->_value = val;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return this->_next;
}

template <typename T>
void Node<T>::setNext(Node* ptr)
{
    _next = ptr;
}