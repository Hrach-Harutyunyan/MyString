#ifndef __STRING__IMPLEMENTATION__HPP__
#define __STRING__IMPLEMENTATION__HPP__

#include "String.hpp"

String::String() : _m_buffer{}, _m_size{} {}

String::String(const char* otherStr) : _m_buffer{}, _m_capacity{}, _m_size{} {
    if(otherStr) {
        while (otherStr[_m_size] != '\0') {
            _m_size++;
        }
        _m_capacity = _m_size;
        _m_buffer = new char(_m_capacity + 1);
        int forCopy = 0;
        while (forCopy < _m_size) {
            _m_buffer[forCopy] = otherStr[forCopy];
            forCopy++;
        }
        _m_buffer[_m_size] = '\0';
    }     
}

String::String(const std::initializer_list<const char*>& initList) : _m_buffer{}, _m_capacity{}, _m_size{} { 
    try {
        if(initList.size() < 2) {
            auto words = *initList.begin();
            while(words[_m_size] != '\0') {
                _m_size++;
            }
            _m_capacity = _m_size;
            _m_buffer = new char(_m_capacity + 1);
            int forCopy = 0;

            while (forCopy < _m_size) {
                _m_buffer[forCopy] = words[forCopy];
                forCopy++;
            }
            _m_buffer[_m_size] = '\0';
        } else throw std::exception();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << ": The init_list should be have 1 argument ( const char* )" << std::endl;
    }
}

String::String(const std::initializer_list<char>& initList) : _m_buffer{}, _m_capacity{initList.size()}, _m_size{} {
    _m_buffer = new char(_m_capacity + 1); 
    for(auto ch : initList) {
        _m_buffer[_m_size++] = ch;
    }
    _m_buffer[_m_size] = '\0';
}

String::String(const String& otherStr) : _m_buffer{}, _m_capacity{otherStr._m_capacity}, _m_size{} {
    this->_m_buffer = new char(this->_m_capacity + 1);
    while(this->_m_size < otherStr._m_size) {
        this->_m_buffer[_m_size] = otherStr._m_buffer[_m_size];
        _m_size++;
    }
    this->_m_buffer[_m_size] = '\0';
}


String::String(String&& otherStr) :  _m_buffer{otherStr._m_buffer}, _m_capacity{otherStr._m_capacity}, _m_size{otherStr._m_size} {
    otherStr._m_buffer = nullptr;
    otherStr._m_capacity = 0;
    otherStr._m_size = 0;
}

String::~String() {
    if(_m_buffer)  delete _m_buffer;
    _m_buffer = nullptr;
}

String& String::operator = (const String& otherStr) {
    if(this != &otherStr) {
        this->_m_capacity = otherStr._m_capacity;
        this->_m_buffer = new char(this->_m_capacity + 1);
        this->_m_size = otherStr._m_size;
        int forCopy = 0;
        while(forCopy < otherStr._m_size) {
            this->_m_buffer[forCopy] = otherStr._m_buffer[forCopy];
            forCopy++;
        }
        this->_m_buffer[_m_size] = '\0';
    }
    return *this;
}

String& String::operator = (const char* otherStr) {
    if(otherStr) {
        if(this->_m_buffer) delete this->_m_buffer;
        int forCopy = 0;

        while(otherStr[forCopy] != '\0') {
            forCopy++;
        }
        this->_m_capacity = forCopy;
        this->_m_size = forCopy;
        forCopy = 0;
        this->_m_buffer = new char(this->_m_capacity + 1);
        while (forCopy < this->_m_size) {
            this->_m_buffer[forCopy] = otherStr[forCopy];
            forCopy++;
        }
        this->_m_buffer[_m_size] = '\0';
    } 
    else {
        this->_m_buffer = nullptr;
        this->_m_capacity = 0;
        this->_m_size = 0;
    }
    return *this;
}

String& String::operator = (String&& rValueString) {
    if(this != &rValueString) {
        this->_m_buffer = rValueString._m_buffer;
        this->_m_capacity = rValueString._m_capacity;
        this->_m_size = rValueString._m_size;
        rValueString._m_buffer = nullptr;
        rValueString._m_capacity = 0;
        rValueString._m_size = 0;
    }
    return *this;
}

const char& String::operator [] (const int index) const {
    return this->_m_buffer[index];
}

char& String::operator [] (const int index) {
    return const_cast<char&>(static_cast<const String&>(*this)[index]);
}

String& String::operator += (const char* otherStr) {
    *this = *this + otherStr;
    return *this;
}

bool String::empty() const {
    return !this->_m_size;
}

std::size_t String::capacity() const {
    return this->_m_capacity;
}

std::size_t String::size() const {
    return this->_m_size;
}

void String::reserve(std::size_t capacity) {
    if(this->_m_capacity < capacity) {
        char * temp = new char(capacity + 1);
        for(int i{}; i < this->_m_size; i++) {
            temp[i] = (*this) [i];
        }
        temp[this->_m_size] = '\0';
        delete[] this->_m_buffer;
        this->_m_buffer = temp;
        this->_m_capacity = capacity;
        temp = nullptr;
    }
}

void String::clear() {
    if(this->_m_buffer) delete[] this->_m_buffer;
    this->_m_size = 0;
    this->_m_capacity = 0;
}

bool String::insert (std::size_t position, const char* otherStr) {
    if(position >= 0 && position <= this->_m_size) {
        std::size_t otherStrSize {};
        while(otherStr[otherStrSize] != '\0') otherStrSize ++;
        std::size_t resultCapacity {this->_m_size + otherStrSize};

        String temp{};
        if(resultCapacity > this->_m_capacity) {
            temp.reserve(resultCapacity);
        } else temp.reserve(this->_m_capacity);

        int tempCopy{};
        while(tempCopy < position) {
            temp[tempCopy] = (*this)[tempCopy];
            tempCopy++;
        }
        int otherCopy {};
        while(otherCopy < otherStrSize) {
            temp[tempCopy] = otherStr[otherCopy];
            ++otherCopy;
            ++tempCopy;
        }

        while (position < this->_m_size)
        {
            temp[tempCopy] = (*this)[position];
            position++;
            tempCopy++; 
        }
        temp[resultCapacity] = '\0';
        temp._m_size = resultCapacity;
        temp._m_capacity = resultCapacity;
        *this = temp;
        temp._m_buffer = nullptr;

        return true;   
    }
    return false;
}

bool String::erase(std::size_t position) {
    if(position >= 0 && position < this->_m_size) {
        int i {};
        for(; i < this->_m_size; i++) {
            if(i == position) {
                while (i < this->_m_size - 1) {
                    (*this)[i] = (*this)[i+1];
                    i++;
                }
                
            }else {continue;}
        }
        (*this)[--this->_m_size] = '\0';
        return true;
    }
    return false;
}

void String::push_back(const char ch) {
    if(this->_m_capacity > this->_m_size) {
        (*this)[this->_m_size++] = ch;
        (*this)[this->_m_size] = '\0';
    } else {
        char* backChar = new char();
        backChar[0] = ch;
        (*this).insert(this->_m_size, backChar);
        delete backChar;
    }
}

void String::pop_back() {
    try {
        if(this->_m_size > 0) {
            (*this)[--this->_m_size] = '\0';
        }
        else throw std::exception();
    } catch (std::exception& e) {
        std::cerr << e.what() << ": In empty string you cant call pop_back function:";
    }
}

void String::append(const char* otherStr) {
    this->insert(this->_m_size, otherStr);
}

int String::compare(const String& otherStr) {
    if(*this < otherStr) return -1;
    if(*this > otherStr) return 1;
    return 0;
}

#endif