#include <iostream>

#include "commonheader.hpp"


int main(){
    I_print add;
    srand((unsigned)time(NULL));
    PF funcs[] = {f1, f2, f3, f4};
    PPF ffuncs[] = {ff1, ff2, ff3, ff4};
    char* funcs_char[] = {"f1", "f2", "f3", "f4"};
    int epses[] = {-2, -3, -4, -5, -6};
    int a, b, k =0, i = 0, j =0;
//    I_print *i_prn = new I_print[12];
    std::cin >> a >> b;
//    i_prn[0] = IntTrap(a, b, power, fn);
//    std::cout << i_prn[0].n << " " << i_prn[0].i_sum << " " << '\n'
//    I_print output = IntTrap(a, b, pow(10, -1*power), fn);
//
//
//
//    delete[] i_prn;
//    return 0;
    I_print output[25];
    
    while(i < 20){
        
        for (int func_i = 0; func_i <= 3; ++func_i){
            for(int eps_i =0; eps_i <= 4; ++eps_i){
               
                return_elm return_elm_out = IntTrap(funcs[func_i], ffuncs[func_i] , a, b, epses[eps_i]);
                return_elm return_elm_out_Rect = IntRect(funcs[func_i], ffuncs[func_i] , a, b, epses[eps_i]);
                
                add.n_Trap = return_elm_out.n;
                add.i_sum_Trap = return_elm_out.i_sum;
                add.name = funcs_char[func_i];
                add.i_toch = return_elm_out.i_toch;
                add.eps = epses[eps_i];
                add.n_Rect = return_elm_out_Rect.n_Rect;
                add.i_sum_Rect = return_elm_out_Rect.i_sum_Rect;
                output[i] = add;
                k++;
                i++;
               
            }
        }
    }
    PrintTabl(output, k);
//    
//    std::cout << "IntRect" << '\n';
//    int k2 = 0;
//    while(j < 20){
//
//        for (int func_j = 0; func_j <= 3; ++func_j){
//            for(int eps_j =0; eps_j <= 4; ++eps_j){
//
//                return_elm return_elm_out = IntRect(funcs[func_j], ffuncs[func_j] , a, b, epses[eps_j]);
//                add.n = return_elm_out.n;
//                add.i_sum = return_elm_out.i_sum;
//                add.name = funcs_char[func_j];
//                add.i_toch = return_elm_out.i_toch;
//                add.eps = epses[eps_j];
//
//                output_rect[j] = add;
//                k2++;
//                j++;
//
//            }
//        }
//    }
//
//
//    PrintTabl(output_rect, k2);
//
    return 0;

}
