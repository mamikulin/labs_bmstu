//
//  min-max-elem.cpp
//  lab_05
//
//  Created by Mike Mikulin on 07.10.2023.
//

#include "hppcommon.hpp"



struct_return min_max_elem_sort(int* mass, int len){
    struct_return min_max_elem_struct_return;
    int min_j = 0, old = 0, k = 0, n = 0;
    for (int i = 0; i < len-1; i ++){
        old = mass[i];
        int  min = 100;
        for (int j = i+1; j < len; j++){
            if (mass[j] < min){
                min = mass[j];
                min_j = j;
            }
            n ++;
        }
       
        if (min_j != i){
            mass[i] = mass[min_j];
            mass[min_j] = old;
            k++;
        }
    }
    
    min_max_elem_struct_return.changes = k;
    min_max_elem_struct_return.comper = n;
    
    return min_max_elem_struct_return;
}
