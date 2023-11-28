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

double det(double **mat, int ij){
    if(ij==1){
        return mat[0][0];
    }
    double **A=new double*[ij-1];
    for (int i = 0; i < ij-1; i++){
        A[i] = new double[ij-1];
    }
    
    double d=0, k=1;
    for (int i = 0; i < ij-1; i++)
    {
        for (int j = 0; j < ij-1; j++){
            A[i][j] = mat[i+1][j+1];
            
        }
    }
    for (int i = 0; i < ij-1; i++){
        d += k*mat[0][i] * det(A,ij-1);
        k*=-1;
        for (int j = 1; j < ij; j++){
            A[j-1][std::min(i,ij-1)] = mat[j][i];
        }
    }
    return d;
}
