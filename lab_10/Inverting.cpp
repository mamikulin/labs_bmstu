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
    print(mat, ij);
    replace(mat, ij, 0, 3);
    replace(mat, ij, 0, 1);
    replace(mat, ij, 1, 2);
 
}

void row_min(double **mat,int ij, int i, int jj, double kdel){
    
    
    kdel = mat[i][jj];
    
    for (int j = 0; j < ij * 2; j++){
        
        mat[i][j] -= mat[0][j] * kdel;
        
    }
}
void column_make_zero(double** mat, int ij, int jj){
    
    
    bool ok = false;
    double kdel;

    replace(mat, ij, jj, 0);
    double k = mat[0][jj];
    
    for (int i =0; i < ij; i++){
        
        for(int j = 0; j < ij * 2; j ++){
            
            if (i == 0){
                mat[0][j] /= k;
                ok = true;
                
                
            } else if (jj != ij && ok == true){
                while (mat[i][jj] != 0){
                    
                    
                    row_min(mat, ij, i, jj, kdel );
                    
                }
            }
            
            
            
        }
        
        
    }
    



    
}

void replace(double** mat, int(ij),int i,int ii){
    
    mat[ij] = mat[i];
    mat[i] = mat[ii];
    mat[ii] = mat[ij];
    
    
}

