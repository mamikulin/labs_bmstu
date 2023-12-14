//
//  bubble-max->min.cpp
//  lab_05
//
//  Created by Mike Mikulin on 12.10.2023.
//

#include "hppcommon.hpp"

struct_return bubble_sort_from_max_to_min(int* mass, int len){
    struct_return bubble_struct_return;
    int k = 0, n = 0;
    bool f;
    for (int i = len; i > 0; i--){
        f = false;
        for (int j = 0; j < len - 1; j++){
            int old = mass[j+1];
            
            if (mass[j] < mass[j+1]){
                mass[j+1] =mass[j];
                mass[j] = old;
                k++;
                f = true;
            }
            n++;
            
        }
        if (f == false){
            break;
        }
    }
    
    bubble_struct_return.changes = k;
    bubble_struct_return.comper = n;
    
    return bubble_struct_return;
}
