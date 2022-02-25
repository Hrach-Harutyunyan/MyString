#include <iostream>

class MyString
{
public:
    MyString ();
    explicit MyString (const char*);
    MyString (const MyString&);
    MyString (MyString&&);
    ~MyString ();
    MyString& operator = (const MyString&);
    MyString& operator = (MyString&&);
    friend const MyString operator + (const MyString& lhs,const MyString& rhs) {
        MyString temp;
        for (int i{}; lhs[i] != '\0'; i++) {
            temp.push_back(lhs[i]);
        }
        for (int j{}; rhs[j] != '\0'; ++j) {
            temp.push_back(rhs[j]);
        }
        return temp;  
    };
    friend std::ostream& operator << (std::ostream& print, const MyString& obj) {
        print << obj._m_buffer;
        return print;
    };
    const char& operator[] (const int) const;
    char& operator[] (const int);
    bool operator == (const MyString&) const;
    const int get_length() const {return _m_size;};
    void push_back (const char);
    char pop_back ();
    bool insert (const int, const char);
    char at(const int);
    int find(const char);

private:
    char* _m_buffer {};
    int _m_size {};
};
