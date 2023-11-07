//
//  main.cpp
//  lab_08
//
//  Created by Mike Mikulin on 31.10.2023.
//

#include <iostream>
#include <iomanip>

int fact(int n);
void print(double **mat, int ij, char t);
void fillmat(double** mat,int ij,double x);
void clear(double** mass);
void fillstaticmat(double B[10][10]);

int main() {
    char t;
    int ij;
    double x = 2;
    std::cout << "размер матрицы    научный(s)/фиксированной точкой(any key): ";
    std::cin >> ij >> t;
    std::cout << '\n';
    
    double **mat = new double *[ij];
    
    fillmat(mat, ij, x);
    print(mat, ij, t);
    clear(mat);
    
    
    
    double B[10][10];
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            B[i][j] = 10 * (i+1) + (j+1);
        }
    }
    
    fillstaticmat(B);
    
    std::cout<<B<<"  "<<B[0]<<"  "<<B[2]<<std::endl;
    std::cout<<B[0][0]<<"  "<<**B <<"  "<<*B[0]<<std::endl;
    std::cout<<*(*(B+1))<<"  "<<*B[1]<<std::endl;
    std::cout<<*(B[0]+1)<<"  " <<*(*B+1)<<std::endl;
    std::cout<<B[0][20]<<"  "<<*(B[0]+20)<<"  "<<*B[2]<<std::endl;

   
    
}
void fillstaticmat(double B[10][10]){
    double **matB = new double *[10];
    
    for (int i = 0; i < 10; i++){
        matB[i] = new double[10];
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            
            matB[i][j] = B[i][j];
        }
    }
    print(matB, 10, 'a');
    clear(matB);
    
}

void fillmat(double** mat,int ij,double x){
    for (int n = 0; n<ij; n++){
        mat[n] =new double [ij];
    }

    for (int j = 0; j < ij; j++){
        
            for (int i = 0; i < ij; i++){
                
                if (abs(j - i) == 1){
                    mat[i][j] = pow((j - i) * x, i+1) / pow(fact(j+1), i+1);
                }else if (i < j){
                    mat[i][j] = mat[i][j-1]  / pow(j+1, i+1);
                }else if (i > j){
                    mat[i][j] = mat[i-1][j]  * ((-x)/fact(j+1));
                }else{
                    mat[i][j] = 1;
                }
            }

    }
}

int fact(int n){
    int r = 1;
    for (n; n > 0; n--){
        r *= n;
    }
    return r;
}

void print(double** mat, int ij, char t){
    
    for (int k = 0; k < std::ceil(static_cast<double>(ij) / 4.0); k++){
        for (int n = 0; n < ij; n++){
            for (int m = 0; m < 4; m++){
                std::cout << std::fixed;
                if (k * 4 + m < ij){
                    
                    if (t == 's'){
                        std::cout << std::setw(20) <<std::scientific << mat[n][k * 4 + m] ;
                    }else{
                        std::cout << std::setw(20) <<std::setprecision(8) << mat[n][k * 4 + m] ;
                    }
                }
                
                
            }
            std::cout << '\n';
        }
        
        std::cout << std::setfill(' ') << std::setw(83) <<
            "-----------------------------------------------------------------------------"
                << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
}

void clear(double** mass){
    delete[] mass;
}
