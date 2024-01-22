//
//  newton.cpp
//  lab_04
//
//  Created by Mike Mikulin on 03.10.2023.
//

#include "head.hpp"

returnans newton(int k, double eps){
    returnans newtonsr;
    double razn = 1;
    
    int n = 0;
    
    double x = -1*k;
    while (std::abs(razn) >= eps){
        
        razn = x - (x - func(x, k) / (1 + k * std::sin(x)));
        x = x - func(x, k) / (1 + k * std::sin(x));
        n ++;
    }
    
    newtonsr.root = x;
    newtonsr.n = n;
    
    return newtonsr;
}
