//
//  mult.cpp
//  lab_10
//
//  Created by Mike Mikulin on 25.11.2023.
//

#include "commonheader.hpp"


void mult(double** A, double* B, double* ans, int ij){
    for(int i = 0; i < ij; i++){
        for (int j = 0; j < ij; j++){
            ans[i] += A[i][j+ij] * B[j];
        }
    }
}
