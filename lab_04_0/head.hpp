//
//  head.hpp
//  lab_04_0
//
//  Created by Mike Mikulin on 10.10.2023.
//


#ifndef head_hpp
#define head_hpp

#include "func.hpp"
#include "math.h"
#include <iostream>

struct returnans {
    double root;
    int n;
};

returnans binary(int k, double eps);
double func(double x, int k);
returnans iterations(int k, double eps);
returnans newton(int k, double eps);

#endif
