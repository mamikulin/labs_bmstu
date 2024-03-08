//
//  mishaslib.hpp
//  mishaslib
//
//  Created by Mike Mikulin on 22.01.2024.
//

#ifndef mishaslib_
#define mishaslib_

/* The classes below are exported */
#pragma once

#include <iostream>

namespace mishaslib
{
class mishaslib{
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
