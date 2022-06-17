#ifndef __ITERATOR__IMPLEMENTATION__HPP__
#define __ITERATOR__IMPLEMENTATION__HPP__

#include "StringIterator.hpp"

StringIterator::StringIterator(const StringIterator& str) : _m_index{str._m_index}, value{str.value} { };

StringIterator::StringIterator(std::size_t index = 0, char* str = nullptr) : _m_index{index}, value{str} { };

StringIterator& StringIterator::operator = (const StringIterator& b) {
    this->value = b.value;
    this->_m_index = b._m_index;
    return *this;
}

bool StringIterator::operator != (const StringIterator& other) const {
    return  _m_index != other._m_index && value == other.value;
}

bool StringIterator::operator == (const StringIterator& other) const {
    return _m_index != other._m_index && value == other.value;
}

typename StringIterator::reference StringIterator::operator * () const {
    return value[_m_index];
}

StringIterator& StringIterator::operator + (int n) {
    _m_index += n;
    return *this;
}

StringIterator& StringIterator::operator ++ () {
    if(value) ++_m_index;
    return *this;
}

StringIterator StringIterator::operator ++ (int n) {
    StringIterator temp(*this);
    ++this->_m_index;
    return temp;
}

StringIterator& StringIterator::operator -- () {
    --this->_m_index;
    return *this;
};

StringIterator StringIterator::operator -- (int n) {
    StringIterator temp(*this);
    --this->_m_index;
    return temp;
};

StringIterator& StringIterator::operator += (int n) {
    this->_m_index += n;
    return *this;
}

StringIterator& StringIterator::operator -= (int n) {
    this->_m_index -= n;
    return *this;
}

StringIterator StringIterator::operator - (int n) {
    StringIterator temp(*this);
    temp._m_index -= n;
    return temp;
};

typename StringIterator::difference_type StringIterator::operator - (const StringIterator& other) {
    return  this->_m_index - other._m_index;
};

bool StringIterator::operator < (const StringIterator& other) {
    return this->_m_index < other._m_index;
};

void StringIterator::swap(StringIterator& b) {
    StringIterator temp(*this);
    *this = b;
    b = temp;
}

#endif