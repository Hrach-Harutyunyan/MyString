#ifndef __STRING__HPP__
#define __STRING__HPP__

#include <iostream>
#include <initializer_list>
#include <limits>

#include "StringIterator.hpp"

class String
{
public:
    String();
    explicit String(const char*);
    explicit String(const std::initializer_list<const char*>&);
    explicit String(const std::initializer_list<char>&);
    String(const String&);
    String(String&&);
    ~String();

public:
    String& operator = (const String&);
    String& operator = (const char*);
    String& operator = (String&&);
    const char& operator [] (const int) const;
    char& operator [] (const int);
    operator bool () { return this->_m_size; }
    operator const char*() { return static_cast<const char*> (this->_m_buffer); }

public:
    friend bool operator == (const String&, const String&);
    friend bool operator != (const String&, const String&);
    friend bool operator < (const String&, const String&);
    friend bool operator <= (const String&, const String&);
    friend bool operator > (const String&, const String&);
    friend bool operator >= (const String&, const String&);
    friend  String operator+ (const String&, const char*);
    friend std::ostream& operator << (std::ostream&, const String&);
    friend std::istream& operator >> (std::istream&, String&);
    String& operator += (const char*);

public:
    void clear();
    void reserve(std::size_t);
    void push_back(const char);
    void pop_back();
    void append(const char*);
    int compare(const String&);
    bool empty() const;
    bool erase(std::size_t);
    bool insert(std::size_t, const char*);
    std::size_t capacity() const;
    std::size_t size() const;

public:
    typedef StringIterator iterator;
    typedef const StringIterator const_iterator;
    
    iterator begin() {return {0, this->_m_buffer};}
    iterator end() {return {_m_size, this->_m_buffer};}
    const_iterator cbegin() const {return {0, this->_m_buffer};}
    const_iterator cend() const {return {_m_size, this->_m_buffer};}

private:
    char* _m_buffer{};
    std::size_t _m_capacity{};
    std::size_t _m_size{};

};

#include "friendOperators.hpp"
#include "StringImplement.hpp"

#endif