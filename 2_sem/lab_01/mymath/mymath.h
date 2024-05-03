#ifndef mymath
#define mymath

/* The classes below are exported */
#pragma once

#include <iostream>

namespace math
{
class Mymath{
public:
    static void foo(){
        std::cout << " ads " << '\n';
    }
    
    // Returns a + b
    static double Add(double a, double b);
    // Returns a - b
    static double Subtract(double a, double b);
    
    static double Dvi(double a, double b);
    
    static double Mult(double a, double b);
};
}

#endif
