#include <iostream>

#include "header.hpp"

int main() {
    double a = 7.4;
    int b = 99;
    mishaslib::mishaslib::foo();
    cout << "a + b = " << mishaslib::mishaslib::Add(a, b) << endl;
    cout << "a - b = " << mishaslib::mishaslib::Subtract(a, b) << endl;
    cout << "a / b = " << mishaslib::mishaslib::Dvi(a, b) << endl;
    cout << "a * b = " << mishaslib::mishaslib::Mult(a, b) << endl;
    return 0;
}
