//
//  make_matrix.cpp
//  lab_10
//
//  Created by Mike Mikulin on 24.11.2023.
//

#include "commonheader.hpp"

void fillmat(double** mat,int ij){
    
    srand ( time(NULL) );
    
    for (int n = 0; n<ij; n++){
        mat[n] =new double[ij * 2];
    }
    
    for (int j = 0; j < ij * 2; j++){
        
            for (int i = 0; i < ij; i++){
                
//                if (abs(j - i) == 1){
//                    mat[i][j] = pow((j - i) * x, i+1) / pow(fact(j+1), i+1);
//                }else if (i < j){
//                    mat[i][j] = mat[i][j-1]  / pow(j+1, i+1);
//                }else if (i > j){
//                    mat[i][j] = mat[i-1][j]  * ((-x)/fact(j+1));
//                }else{
//                    mat[i][j] = 1;
//                }
                
                if (j<ij){
                    mat[i][j] = 1 + std::rand() / ((RAND_MAX + 1u) / 9);
                }else if (j == i +ij){
                    mat[i][j] = 1;
                }else{
                    mat[i][j] = 0;
                }
                
            }

    }
}

void print(double **mat, int ij){
    int jj = ij * 2;
    
    for (int i = 0; i < ij; i++){
        for (int j = 0; j < jj; j++ ){
            if (j == ij){
                std::cout << "| ";
            }
            std::cout << std::setw(13)<< mat[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
}
    


