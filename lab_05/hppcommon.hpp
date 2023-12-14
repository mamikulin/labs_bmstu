//
//  hppcommon.hpp
//  lab_05
//
//  Created by Mike Mikulin on 18.10.2023.
//

#ifndef hppcommon_hpp
#define hppcommon_hpp

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy

#include <stdio.h>

struct struct_return{
    int changes;
    int comper;
};

struct_return min_max_elem_sort_from_max_to_min(int* mass, int len);
struct_return bubble_sort_from_max_to_min(int* mass, int len);
char* razdel();
void output(int* mass, int changes, int comper, int len);
struct_return bubble_sort(int* mass, int len);
struct_return min_max_elem_sort(int* mass, int len);
int* rand_int(int len);
int* collect_stat(int* mass, int len);

#endif /* hppcommon_hpp */
