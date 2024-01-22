//
//  binary.cpp
//  lab_04
//
//  Created by Mike Mikulin on 03.10.2023.
//

#include "head.hpp"

returnans binary(int k, double eps){
    returnans binaryans;
    double x1 = -1 * k;
    double x2 = k;
    double xp = 0;
    int n = 0;
    
    while (x2 - x1 > eps){
        if (func(x1, k) * func(x2, k) < 0){
            xp = x1;
            x1 = (x1 + x2)/2;
        }
        else{
            x2 = x1;
            x1 = xp;
            
        }
        n ++;
        
    }
    
    binaryans.root = x2;
    binaryans.n = n;
    
    return binaryans;
}


