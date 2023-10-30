#include "../header/dinamicArray.h"

template <class T>
DArray<T>::DArray() : _size(0), _capacity(1)
{
    _array = new T[_capacity];
}

template <class T>
DArray<T>::DArray(const std::initializer_list<T> & coord)
{
    _array = new T[coord.size()];
    _size = coord.size();
    _capacity = coord.size();

    size_t i = 0;
    for (auto &el : coord) {
        _array[i++] = el;
    }
}

template <class T>
DArray<T>::DArray(const DArray & other)
{
    this->_array = new T[_capacity];
    this->_size = other._size;
    this->_capacity = other._capacity;

    if (other._capacity > this->_capacity) {
        this->realocate(other._capacity);
    } 
}

template <class T>
DArray<T>::DArray(DArray&& other) noexcept
{
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(_array, other._array);
}

template <class T>
DArray<T>::~DArray() noexcept
{
    if (_capacity > 0) {
        _size = 0;
        _capacity = 0;
        delete[] _array;
        _array = nullptr;
    }
}

template <class T>
void DArray<T>::pushBack(const T & element)
{
    if (_size >= _capacity) {
        _capacity *= 2;
        T* newArray = new T[_capacity];

        for (size_t i = 0; i < _size; ++i) {
            newArray[i] = this->_array[i];
        }

        delete[] this->_array;
        this->_array = newArray;
    }
    
    this->_array[_size++] = element;
}

template <class T>
void DArray<T>::deleteToIndex(size_t index)
{
    if (index < 0 || index >= _size) {
        throw std::length_error("Error! DArray deleteToIndex: Invalid index for deletion.");
    }

    for (size_t i = index; i < _size - 1; ++i) {
        this->_array[i] = this->_array[i + 1];
    }

    --_size;
}

template <class T>
T & DArray<T>::operator[](size_t index)
{
    if (index >= _size) {
        throw std::range_error("Error! DArray operator[]: Invalid index");
    }

    return _array[index];
}

template <class T>
void DArray<T>::operator=(const DArray & other)
{
    if (this == &other) // Проверка на самоприсваивание
        return;

    if (other._capacity != this->_capacity) {
        delete[] this->_array; // Освобождаем старый массив

        if (other._capacity > this->_capacity) {
            this->realocate(other._capacity);
        } else {
            this->_array = new T[other._capacity];
            this->_capacity = other._capacity;
        }
    }

    this->_size = other._size;
    memcpy(this->_array, other._array, other._size * sizeof(T));
}


template <class T>
void DArray<T>::operator=(DArray&& other)
{
    std::swap(_size, other._size);
    std::swap(_array, other._array);
    std::swap(_capacity, other._capacity);
}

template <class T>
size_t DArray<T>::getSize() const
{
    return _size;
}

template <class T>
size_t DArray<T>::calculateCapacity(const size_t minSize)
{
    size_t newCapacity = _capacity;
    while (newCapacity < minSize) {
        if (newCapacity >= std::numeric_limits<size_t>::max() - newCapacity) {
            return std::numeric_limits<size_t>::max();
        }

        newCapacity *= 2;
    }

    return newCapacity;
}

template <class T>
void DArray<T>::realocate(const size_t minSize)
{
    size_t newCapacity = calculateCapacity(minSize);

    T* tmp = new T[newCapacity];

    for (size_t i = 0; i < _size; ++i) {
        tmp[i] = this->_array[i];
    }

    delete[] this->_array;
    _capacity = newCapacity;
}