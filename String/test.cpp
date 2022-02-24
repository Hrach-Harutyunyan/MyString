#include "myString.h"

int main () {

    MyString obj1 ("hello ");
    MyString obj2 ("world");
    MyString obj3 ;
    obj3 = obj1;
    std::cout << "obj1 = " << obj1 << "   obj1.size = " << obj1.get_length() <<  std::endl;
    std::cout << "obj2 = " << obj2 << "   obj2.size = " << obj2.get_length() << std::endl;
    std::cout << "obj3 = " << obj3 << "   obj3.size = " << obj3.get_length() << std::endl;
    obj2.insert(5,'!');
    std::cout << "obj2 = " << obj2 << "   obj2.size = " << obj2.get_length() << std::endl;
    std::cout << "find:  "  << obj2.find('o') << std::endl;
    std::cout << std::boolalpha << (obj1 == obj3);


    return 0;
}