//
//  main.cpp
//  lab_10
//
//  Created by Mike Mikulin on 24.11.2023.
//

#include "commonheader.hpp"

int main(int argc, const char * argv[]) {
    int ij;
    std::cin >> ij;
    double** mat = new double*[ij+1];
    double* B = new double[ij];
    double* ans = new double[ij];
    
    fillmat(mat, ij);
    
//    print(mat, ij);
    
    for (int i = 0; i < ij; i++){
        for (int j = 0; j < ij; j++){
            std::cout << i << " " << j << " ";
            std::cin >> mat[i][j];
            std::cout << '\n';
        }
    }

    print(mat, ij);
    inverting(mat, ij);
    print(mat, ij);
    
    for (int i = 0; i < ij; i++){
        printf("%d строчка равна: ", i+1);
        std::cin >> B[i];
    }

    
    mult(mat, B, ans, ij);
    
    std::cout << "Ответ: " << '\n';
    for (int i = 0; i < ij; i++){
        std::cout << "X"<< i+1 << ": "<<  ans[i] << '\n';
    }

    delete[] ans;
    delete[] B;
    for (int i = 0; i < ij; i++){
        delete[] mat[i];
    }
    return 1;
}
