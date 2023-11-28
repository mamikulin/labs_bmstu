//
//  main.cpp
//  lab_08
//
//  Created by Mike Mikulin on 31.10.2023.
//

#include <iostream>
#include <iomanip>

int fact(int n);
//template <typename T>
void print(double **mat, int ij, char t, int p);
void fillmat(double** mat,int ij,double x);
void clear(double** mass, int ij);
void fillstaticmat(double B[10][10]);

int main() {
    char t;
    int ij, p;
    
    double x = 1;
    std::cout << "размер матрицы    научный(s)/фиксированной точкой(any key)   setprecision: ";
    std::cin >> ij >> t >> p;
    std::cout << '\n';
    
    double **mat = new double *[ij];
    
    fillmat(mat, ij, x);
    print(mat, ij, t, p);
    clear(mat, ij);
    
    
    
    double B[10][10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            B[i][j] = 10 * (i+1) + (j+1);
        }
    }
//    print(B, ij, t, p);
    fillstaticmat(B);

    std::cout<<B<<"  ";
//    std::cin>>x;
    std::cout<<*B[8]<<"  "<<B[9]<<std::endl;
    std::cout<<B[0][5]<<"  "<<*(*B+4) <<"  "<<*B[8]<<std::endl;
    std::cout<<*(*(B+7))<<"  "<<*B[1]<<std::endl;
    std::cout<<*(B[4]+1)<<"  " <<*(*B+1)<<std::endl;
    std::cout<<B[0][20]<<"  "<<*(*B+40)<<"  "<<*B[2]<<std::endl;

   
}
void fillstaticmat(double B[10][10]){
    double **mat = new double *[10];
    
    
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j < 10; j++){
            mat[i] = B[i];
            
        }
    }
    print(mat, 10, 'a', 8);
   
    
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
//template <typename T>
void print(double **mat, int ij, char t, int p){
    int nj = std::floor(80 / static_cast<double>(p + 15));
    
    for (int k = 0; k < std::ceil(static_cast<double>(ij) / nj); k++){
            for (int n = 0; n < ij; n++){
                for (int m = 0; m < nj; m++){
                    std::cout << std::fixed;
                    if (k * nj + m < ij){
                        
                        if (t == 's'){
                            std::cout << std::setw(20) <<std::scientific << mat[n][k * nj + m] ;
                        }else{
                            std::cout << std::setw(20) <<std::setprecision(p) << mat[n][k * nj + m] ;
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

void clear(double** mass, int ij){
    for (int i=0; i < ij; i++){
        delete[] mass[i];
    }
    delete[] mass;
}
