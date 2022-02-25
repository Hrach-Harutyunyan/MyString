#include <iostream>

class MyString
{
public:
    MyString ();
    explicit MyString (const char*);
    MyString (const MyString&);
    MyString (MyString&&);
    MyString& operator = (const MyString&);
    MyString& operator = (MyString&&);
    char& operator[] (const int);
    const char& operator[] (const int) const;
    bool operator == (const MyString&) const;
    ~MyString ();

public:
    char pop_back ();
    char at(const int);
    int find(const char);
    void push_back (const char);
    bool insert (const int, const char);
    const int get_length() const {return _m_size;};

public:
    friend const MyString operator + (const MyString& lhs,const MyString& rhs) {
        MyString temp;
        for (int i{}; i < lhs._m_size; i++) {
            temp.push_back(lhs[i]);
        }
        for (int j{}; j < rhs._m_size; ++j) {
            temp.push_back(rhs[j]);
        }
        return temp;  
    };
    friend std::ostream& operator << (std::ostream& print, const MyString& obj) {
        print << obj._m_buffer;
        return print;
    };

protected:
    friend void swap (MyString& lhs, MyString& rhs) {
        if (&lhs != &rhs) {
            using std::swap;
            swap (lhs._m_buffer, rhs._m_buffer);
            swap (lhs._m_size, rhs._m_size);
        }
    };

protected:
    char* _m_buffer {};
    int _m_size {};
};