#include "header.h"

int main() {
    
    MySet<int> a, b, c;
   
    std::cout << a.get_size() << '\n';
    std::cout << a.get_max_size() << '\n';
    std::cout << typeid(a).name()<< '\n';
    a.add_Element(1);
    a.add_Element(4);
    a.add_Element(6);
    a.add_Element(5);
    a.add_Element(5);
    a.add_Element(5);

    b.add_Element(1);
    b.add_Element(2);
    b.add_Element(3);
    b.add_Element(4);

    std::cout << a<< '\n';
    std::cout << b<< '\n';
    a -= b;
    std::cout << a << '\n';
    std::cout <<"a:   " <<  typeid(a).name()<< '\n';
    std::cout <<"c:   " <<  typeid(c).name()<< '\n';
    std::cout <<"b:   " << typeid(b).name()<< '\n';
    std::cout <<"a+b: " <<  typeid((a + b)).name()<< '\n';
    // c = a + b;
    bool k = c == b;
    std::cout << k << '\n';
    // std::cout << c << '\n';
    
    
    // std::cout << a << '\n';
    // a.delete_Element(2);
    // a.delete_Element(3);
    // a.delete_Element(2);
    // a.delete_Element(3);
    // a.delete_Element(2);
    // a.delete_Element(2);


    // std::cout << a << '\n';
    // b = a;
    // std::cout << b << '\n';

    // std::cout << a[3] << '\n';
    // std::cout << a.find(59) << '\n';

    // std::cout << a.get_size() << '\n';
    // std::cout << a.get_max_size() << '\n';
   
    return 0;
}
