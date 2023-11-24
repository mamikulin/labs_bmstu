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
    double** mat = new double*[ij];
    
    fillmat(mat, ij);
    print(mat, ij);
    inverting(mat, ij);
    print(mat, ij);
    
    
    return 1;
}
