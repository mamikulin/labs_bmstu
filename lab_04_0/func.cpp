//
//  func.cpp
//  lab_04
//
//  Created by Mike Mikulin on 04.10.2023.
//

#include "head.hpp"


double func(double x, int k){
    double y = x - k * std::cos(x);
    return y;
}
