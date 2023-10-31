//
//  IntRect.cpp
//  lab_06
//
//  Created by Mike Mikulin on 19.10.2023.
//

#include "commonheader.hpp"

return_elm IntRect(PF fn, PPF ffn, int a,int b, int eps ){
    double delx = b - a, S0 = 0, S = 0, y = 0;
    int n = 1;
    return_elm ansRect;
    
    S0 = delx * fn(a);
    
    while (abs(S - S0) >= pow(10, eps)){
        
        S0 = S;
        S = 0;
        
        for( int i = 0; i < n; i++){
            y = fn(a + i * delx);
    
            S += abs(y);
            
        }
        S *= delx;
        
        n *= 2;
        delx /= 2;
        
    }
    ansRect.n_Rect = n;
    ansRect.i_sum_Rect = S;
    ansRect.i_toch = ffn(a, b);
    
    return ansRect;
}
