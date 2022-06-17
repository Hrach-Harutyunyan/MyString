#ifndef __FRIEND__OPERATORS__HPP__
#define __FRIEND__OPERATORS__HPP__

#include "String.hpp"

bool operator == (const String& str, const String& otherStr) {
    if(str._m_size != otherStr._m_size) return false;
    else {
        if(!str._m_size) return true;
        else {
            for(int i{}; i < str._m_size; i++) {
                if(str._m_buffer[i] != otherStr._m_buffer[i]) return false;
            }
            return true;
        }
    } 
}

bool operator != (const String& str, const String& otherStr) {
    return !(str == otherStr);
}

bool operator < (const String& str, const String& otherStr) {
    if(str._m_size && otherStr._m_size) {
        for(int i{}; i < str._m_size && i < otherStr._m_size; i++) {
            if((str)[i] < otherStr[i]) return true;
            else if ((str)[i] > otherStr[i]) return false;
        }
    }
    return (str._m_size < otherStr._m_size) ? true :  false;
}

bool operator <= (const String& str, const String& otherStr) {
    return (str == otherStr) || (str < otherStr);
}

bool operator > (const String& str, const String& otherStr) {
    return !(str <= otherStr);
}

bool operator >= (const String& str, const String& otherStr) {
    return !(str < otherStr);
}

String operator+ (const String& str,  const char* otherStr) {
    int otherStrSize{};
    while(otherStr[otherStrSize] != '\0') otherStrSize++;
    int size = otherStrSize + str._m_size;
    char* concat = new char(size+1);
    int i = 0;
    for(; i < str._m_size; i++) {
        concat[i] = str[i];
    }
    for(int j = 0; j < otherStrSize; j++) {
        concat[i] = otherStr[j];
        i++;
    }
    concat[size] = '\0';
    String result (concat);
    delete[] concat;
    return result;
}


std::ostream& operator << (std::ostream& print, const String& str) {
    print << str._m_buffer;
    return print;
}

std::istream& operator >> (std::istream& Input, String& mystring) {		
    int buffSz = 200;	
    char* buff = new char(200);

    Input.get(buff, buffSz, '\n');
    mystring = String(buff);

    Input.clear();
    Input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    delete[] buff;

    return Input;
}

std::ostream& operator << (std::ostream& print,const StringIterator& it) {
    print << *it; 
    return print;
}



#endif