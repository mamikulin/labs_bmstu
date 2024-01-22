//
//  min_max_elem-max->min.cpp
//  lab_05
//
//  Created by Mike Mikulin on 12.10.2023.
//

#include "hppcommon.hpp"

struct_return min_max_elem_sort_from_max_to_min(int* mass, int len){
    struct_return min_max_elem_struct_return;
    int max_j = 0, old = 0, k = 0, n = 0;
    for (int i = 0; i < len-1; i ++){
        old = mass[i];
        int  max = -100;
        for (int j = i; j < len; j++){
            if (mass[j] > max){
                max = mass[j];
                max_j = j;
            }
            n ++;
        }
        if (max_j != i){
            mass[i] = mass[max_j];
            mass[max_j] = old;
            k++;
        }
    }
    
    min_max_elem_struct_return.changes = k;
    min_max_elem_struct_return.comper = n;
    
    return min_max_elem_struct_return;
}
