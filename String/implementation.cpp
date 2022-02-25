#include "myString.h"

MyString::MyString () : _m_buffer {new char[1]} , _m_size {} {
    _m_buffer[0] = '\0';
}

MyString::MyString (const char* rhs) : _m_buffer {new char[1]},_m_size {}  {
    if (rhs) {
        for (int i{}; rhs[i] != '\0'; ++i) {
            this->push_back (rhs[i]);
        }
    }
}

MyString::MyString (const MyString& rhs) : _m_buffer {} , _m_size {} {
    if (rhs[0] == '\0'){
        _m_buffer = new char[1];
        _m_buffer[0] = '\0';
        _m_size = 0;
    } else {
        _m_buffer = new char[rhs._m_size + 1];
        for (int i = 0; rhs[i] != '\0'; i++) {
            this->push_back (rhs[i]);
        }
    }
} 

MyString::MyString (MyString&& rhs) : _m_buffer {} , _m_size {} {
    this->_m_buffer = rhs._m_buffer;
    rhs._m_buffer = nullptr;
    this ->_m_size = rhs._m_size;
    rhs._m_size = 0;
}

MyString& MyString::operator = (const MyString& rhs) {
    if(this == &rhs) return *this;
    _m_buffer[0] = '\0';
    this->_m_size = 0;
    for (int i = 0; rhs[i] != '\0'; i++) {
        this->push_back (rhs[i]);
    }
    return *this;
}

MyString& MyString::operator = (MyString&& rhs) {
    this->_m_buffer = rhs._m_buffer;
    rhs._m_buffer = nullptr;
    this ->_m_size = rhs._m_size;
    rhs._m_size = 0;
    return *this;
};

const char& MyString::operator[] (const int index) const {
    if(index >= 0 && index < this->_m_size)
        return this->_m_buffer[index];
};

char& MyString::operator[] (const int index) {
    return const_cast < char& > (static_cast < const MyString& > (*this)[index]);
};

bool MyString::operator == (const MyString& other) const {
    bool result = true;
    if (this->_m_size != other._m_size) return !result;
    for (int i{}; (*this)[i] != '\0'; ++i) {
        if ((*this)[i] != other[i])
        return !result;
    }
    return result;
};

void MyString::push_back (const char element) {
    this->_m_buffer[_m_size] = element;
    this->_m_buffer[++_m_size] = '\0';
};

char MyString::pop_back () {
    if (_m_size) {
        char ch = this->_m_buffer[--_m_size];
        this->_m_buffer[_m_size] = '\0';
        return ch;
    }
}

bool MyString::insert (const int index, const char element) {
    bool result = true;
    if(index >= 0 && index <= _m_size) {
        char* temp = new char[++_m_size];
        for(int indexTemp{}, indexBuffer{}; indexTemp <= _m_size && indexBuffer < _m_size ;) {
            if(indexTemp == index) {
                temp[indexTemp++] = element;
            } else {
                temp[indexTemp++] = _m_buffer[indexBuffer++];
            }
        }
        delete[] _m_buffer;
        _m_buffer = temp;
        temp = nullptr;
        return result;
    }
    return !result;
};


int MyString::find (const char element) {
    for (int i = 0; (*this)[i] != '\0'; i++) {
        if((*this)[i] == element) return i;
    }
    return -1;
}

char MyString::at (const int index) {
    try {
        if(index >= 0 && index < _m_size)
        return (*this)[index];
        throw (std::exception());
    }
    catch(const std::exception& e) {
        std::cerr << e.what () << ": Wrong index:\n";
    }
    
}

MyString::~MyString () {
    delete[] _m_buffer;
    _m_buffer = nullptr;
};
