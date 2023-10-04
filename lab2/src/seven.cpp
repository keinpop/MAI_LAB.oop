#include "../header/seven.h"

Seven::Seven() : _size(0), _array{nullptr}
{
    std::cout << "Default constructor" << std::endl;
}

Seven::Seven(const size_t & n, unsigned char elem)
{
    std::cout << "Fill constructor zeros" << std::endl;
    _array = new unsigned char[n];
    _size = n;

    if ((elem >= '0') && (elem <= '6')) {
        std::fill_n(_array, n, elem);
    } else {
        throw std::range_error("Fille constructor: Invalid symbol");
    }
}

Seven::Seven(const std::initializer_list<unsigned char> & str)
{
    std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[str.size()];
    _size = str.size();

    size_t i = str.size() - 1;
    for (auto &c : str) {
        if (c >= '0' && c <= '6') {
            _array[i--] = c;
        } else {
            throw std::range_error("Initializer list: Invalid symbol");
        }
    }
}

Seven::Seven(const Seven &other)
{
    this->_size = other._size;
    this->_array = new unsigned char[_size];
    
    memcpy(this->_array, other._array, this->_size * sizeof(unsigned char));
}

Seven::Seven(const std::string & other)
{
    std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[other.size()];
    _size = other.size();
    size_t iter{0}; 
    for (int i = _size - 1; i >= 0; --i) {
        if (other[i] >= '0' && other[i] <= '6') {
            _array[iter++] = other[i];
        } else {
            throw std::range_error("Base contructor: Invalid symbol");
        }
    } 
}

Seven::Seven(Seven&& other) noexcept
{  
    std::cout << "Move constructor" << std::endl;
    std::swap(_size, other._size);
    std::swap(_array, other._array);
}

Seven::~Seven() noexcept
{
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

size_t Seven::getSize() const
{
    return _size;
}

unsigned char Seven::getArrayElem(size_t iter)
{
    return _array[iter];
}

void Seven::setArrayElem(size_t iter, unsigned char value)
{
    _array[iter] = value;
}

void Seven::resizeArrayPlus()
{
    unsigned char* tmp = new unsigned char[_size + 1];
    tmp[_size] = '0';
    std::memcpy(tmp, _array, (_size) * sizeof(unsigned char));

    delete[] this->_array;
    _array = tmp;
    _size++;
}

void Seven::resizeArrayMinus()
{
    unsigned char* tmp = new unsigned char[_size - 1];
    tmp[_size] = '0';
    std::memcpy(tmp, _array, (_size - 1) * sizeof(unsigned char));

    delete[] this->_array;
    _array = tmp;
    _size--;
}

unsigned char & Seven::operator[](size_t index)
{  
    if (index >= _size) {
        throw std::range_error("Invalid index");
    }

    return _array[index];
}

bool Seven::operator>(const Seven & other) const
{
    if (_size > other._size)
        return true;

    if (_size < other._size)
        return false;

    for (int i = _size - 1; i >= 0; --i) {
        if (_array[i] > other._array[i])
            return true;

        if (_array[i] < other._array[i])
            return false;
    }

    return false;
}

bool Seven::operator>=(const Seven & other) const
{
    if (_size > other._size)
        return true;

    if (_size < other._size)
        return false;

    for (int i = _size - 1; i >= 0; --i) {
        if (_array[i] > other._array[i])
            return true;

        if (_array[i] < other._array[i])
            return false;
    }

    return true;
} 

bool Seven::operator<(const Seven & other) const
{
    return !operator>=(other);
}

bool Seven::operator<=(const Seven & other) const
{
    return !operator>(other);
}

bool Seven::operator==(const Seven & other) const 
{
    if (_size != other._size)
        return false;
    
    for (int i = 0; i < _size; i++) {
        if (_array[i] != other._array[i]) 
            return false;
    }

    return true;
}

bool Seven::operator!=(const Seven & other) const
{
    return !operator==(other);
}

std::ostream & operator<<(std::ostream & stream, const Seven & seven)
{
    if (seven._size == 0) 
        return stream << "Empty row";

    for (int i = seven._size - 1; i >= 0; --i) {
        stream << seven._array[i];
    }
    
    return stream;
}

std::istream & operator>>(std::istream & stream, Seven & seven)
{
    std::string str;
    stream >> str;
    std::reverse(str.end(), str.begin());
    Seven tmp(str);
    seven = tmp;

    return stream;
}

void Seven::operator=(Seven & other)
{
    this->_size = other._size;
    this->_array = new unsigned char[_size];
    memcpy(this->_array, other._array, this->_size * sizeof(unsigned char));
}

Seven Seven::operator+(const Seven & other) const
{
    int carry = 0;
    int i = 0;
    int sum = 0;
    int j = std::max(other._size, this->_size);

    Seven tmp(j, '0');

    while (i < j) {
        if (i < other._size) 
            sum += (other._array[i] - '0');

        if (i < this->_size) 
            sum += (this->_array[i] - '0');
        
        sum += carry;
        carry = 0;

        if (sum >= 7) {
            carry = 1;
            sum %= 7;
        }
        
        tmp._array[i] = sum + '0';
        
        sum = 0;
        ++i;
    }

    if (carry) {
        tmp.resizeArrayPlus();
        tmp._array[j] = carry + '0';
    }
    
    return tmp;
}

Seven Seven::operator-(const Seven & other) const
{
    if (*(this) < other) { // abs
        Seven res(1, '0');
        return res;
    }

    int i = 0;
    int j = std::max(this->_size, other._size);
    int sum = 0;
    Seven tmp(j, '0');
    int takeUnit = 0;
    int whatSub, fromSub;

    while (i < j) {
        whatSub = 0;
        fromSub = 0;
        if (i < other._size) 
            fromSub = other._array[i] - '0';

        if (i < this->_size) 
            whatSub = this->_array[i] - '0';
        
        sum = whatSub - fromSub  - takeUnit;
        takeUnit = 0;

        if (sum < 0 && i + 1 != this->_size) {
            takeUnit += 1;
            sum += 7;
        }
        
        tmp._array[i] = sum + '0';
        ++i;
        sum = 0;
    }

    while (tmp._array[j - 1] == '0' && tmp._size > 1) {
        tmp.resizeArrayMinus();
        --j;
    }

    return tmp;
}

Seven Seven::operator+=(const Seven & other)
{
    Seven tmp = *(this) + other;
    *(this) = tmp;

    return *(this);
}

Seven Seven::operator-=(const Seven & other)
{
    Seven tmp = *(this) - other;
    *(this) = tmp;

    return *(this);
}