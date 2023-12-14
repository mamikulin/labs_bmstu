//
//  collect_stat.cpp
//  lab_05
//
//  Created by Mike Mikulin on 05.12.2023.
//

#include "hppcommon.hpp"

int* collect_stat(int* mass, int len){
    
    int* stat = new int[4];
    
    int *mass_bubble = new int[len];
    int *mass_min_max_elem = new int[len];
    
    for (int i=0; i < len; i++){
        mass_bubble[i] = mass[i];
        mass_min_max_elem[i] = mass[i];
    }
   
    struct_return bubble_struct_return = bubble_sort(mass_bubble, len);
    struct_return min_max_elem_struct_return = min_max_elem_sort(mass_min_max_elem, len);
    
    int min_max_elem_changes = min_max_elem_struct_return.changes;
    int min_max_elem_comper = min_max_elem_struct_return.comper;
    
    int bubble_changes = bubble_struct_return.changes;
    int bubble_comper = bubble_struct_return.comper;
    
    stat[0] = min_max_elem_comper;
    stat[1] = min_max_elem_changes;
    stat[2] = bubble_comper;
    stat[3] = bubble_changes;
    

    delete[] mass_bubble;
    delete[] mass_min_max_elem;
    
    return stat;
}
