#include <iostream>

#include "header.h"



int main() {
    double a = 7.4;
    int b = 99;
    math::Mymath::foo();
    std::cout << "a + b = " <<  math::Mymath::Add(a, b) << std::endl;
    std::cout  << "a - b = " << math::Mymath::Subtract(a, b) << std::endl;
    std::cout  << "a / b = " << math::Mymath::Dvi(a, b) << std::endl;
    std::cout  << "a * b = " << math::Mymath::Mult(a, b) << std::endl;

    std::cout  << "(a + b)*2 = " << lib::Mylib::Add_and_double(a, b) << std::endl;
    std::cout  << "a * b * 3 = " << lib::Mylib::Mult_and_triple(a, b) << std::endl;
    return 0;
}
