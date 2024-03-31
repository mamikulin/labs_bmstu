#include "header.h"

int main() {
    
    MyVector<int> a, b;
    std::cout << a.get_size() << '\n';
    std::cout << a.get_max_size() << '\n';

    a.add_element(10);
    a.add_element(9);
    a.add_element(20);
    a.add_element(59);
    a.add_element(30);
    a.add_element(13);
    a.add_element(10);
    a.add_element(5);
    a.add_element(3);
    a.add_element(2);
    

    std::cout << a << '\n';
    MyVector<int> c(a);
    std::cout << c << '\n';

    a.delete_element(2);
    a.delete_element(3);
    a.delete_element(2);
    a.delete_element(3);
    a.delete_element(2);
    a.delete_element(2);


    std::cout << a << '\n';
    b = a;
    std::cout << b << '\n';
    
    std::cout << a[3] << '\n';
    std::cout << a.find(59) << '\n';

    std::cout << a.get_size() << '\n';
    std::cout << a.get_max_size() << '\n';
   
    return 0;
}
