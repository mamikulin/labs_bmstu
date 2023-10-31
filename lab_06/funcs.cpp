//
//  funcs.cpp
//  lab_06
//
//  Created by Mike Mikulin on 19.10.2023.
//

#include "commonheader.hpp"
//
//double func(double x, int fn){
//    switch (fn) {
//        case 1:
//            return x;
//            break;
//        case 2:
//            return sin(22 * x);
//            break;
//        case 3:
//            return pow(x, 4);
//            break;
//        case 4:
//            return atan(x);
//            break;
//
//        default:
//            return 0;
//    }
//}

double f1(double x){
    return x;
}
double f2(double x){
    return sin(22*x);
}
double f3(double x){
    return pow(x,4);
}
double f4(double x){
    return atan(x);
}


double ff1(int a, int b){
    return (b*b - a*a)/2.0;
}
double ff2(int a, int b){
    return (cos(a*22.0) - cos(b*22.0))/22.0;
}
double ff3(int a, int b){
    return (b*b*b*b*b - a*a*a*a*a)/5.0;
}
double ff4(int a, int b){
    return b*atan(b) - a*atan(a) - (log(b*b+1) - log(a*a+1))/2.0;;
}



