//
//  iterations.cpp
//  lab_04
//
//  Created by Mike Mikulin on 03.10.2023.
//

#include "iterations.hpp"



returnans iterations(int k, double eps){
    returnans iterationsans;
    double razn = 1;
    int n = 1;
    
    double x = -1 * k;
    
    while (std::abs(razn) >= eps){
        razn = k * std::cos(x) - x;
        
        x = k * std::cos(x);
        n ++;
        
    }
    
    iterationsans.root = x;
    iterationsans.n = n;
    
    return iterationsans;
}
