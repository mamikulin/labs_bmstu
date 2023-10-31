//
//  commonheader.hpp
//  lab_06
//
//  Created by Mike Mikulin on 19.10.2023.
//

#ifndef commonheader_hpp
#define commonheader_hpp

#include <stdio.h>
#include <iostream>
#include "math.h"
#include <iomanip>
#include <sstream>
#include <cstring>

typedef double (*PF)(double);
typedef double (*PPF)(int, int);


struct I_print{    //данные для печати результатов интегрирования
    const char* name;//название функции
    double i_sum_Trap;    //значение интегральной суммы
    double i_toch;    //точное значение интеграла
    int n_Trap;    //число разбиений области интегрирования
            //при котором достигнута требуемая точность
    int eps;
    double i_sum_Rect;
    int n_Rect;
};
struct return_elm{
    double i_sum;
    int n;
    double i_toch;
    double i_sum_Rect;
    int n_Rect;
    
};
void PrintTabl(I_print i_prn[], int k);

return_elm IntRect(PF fn, PPF ffn, int a,int b, int eps );
return_elm IntTrap(PF fn, PPF ffn, int a,int b, int eps );

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);

double ff1(int a, int b);
double ff2(int a, int b);
double ff3(int a, int b);
double ff4(int a, int b);


#endif /* commonheader_hpp */
