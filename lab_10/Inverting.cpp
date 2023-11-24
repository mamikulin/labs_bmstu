//
//  Inverting.cpp
//  lab_10
//
//  Created by Mike Mikulin on 24.11.2023.
//
#include "commonheader.hpp"


void inverting(double** mat, int ij){
    for (int i = 0; i < ij; i++){
        column_make_zero(mat, ij, i);
    }
 
}

void row_min(double **mat,int ij, int i, int jj, double kdel){
    
    
    kdel = mat[i][jj];
    
    for (int j = 0; j < ij * 2; j++){
        
        mat[i][j] -= mat[jj][j] * kdel;
        
    }
}
void column_make_zero(double** mat, int ij, int jj){
    double k = mat[jj][jj];
    bool ok = false;
    double kdel;
    
    for (int i = 0; i < ij; i++){
        
        for(int j = 0; j < ij * 2; j ++){
            
            if (i == jj){
                mat[i][j] /= k;
                ok = true;
            }
            else if (jj != ij-1 && ok == true){
                while (mat[i][jj] != 0){
                    
                    
                    row_min(mat, ij, i, jj, kdel );
                    
                }
            }
        }
        
    }
    
}

