//
//  bubble.cpp
//  lab_05
//
//  Created by Mike Mikulin on 10.10.2023.
//

#include "hppcommon.hpp"


struct_return bubble_sort(int* mass, int len){
    struct_return bubble_struct_return;
    int k = 0, n = 0;
    for (int i = len; i > 0; i--){
        for (int j = 0; j < len - 1; j++){
            int old = mass[j];
            
            if (mass[j] > mass[j+1]){
                mass[j] =mass[j+1];
                mass[j+1] = old;
                k++;
            }
            ++n; 
            
        }
    }
    bubble_struct_return.mass = mass;
    bubble_struct_return.changes = k;
    bubble_struct_return.comper = n;
    
    return bubble_struct_return;
}
