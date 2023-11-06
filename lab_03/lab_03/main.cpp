#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>

void tfirst();
void tsecond();
void tthird();
void tfourth();

int main(){
    int num;
    while (true){
        std::cout << "введите номер задания: ";
        std::cin >> num;
        switch (num){
            case 1:
                tfirst();
                break;
            case 2:
                tsecond();
                break;
            case 3:
                tthird();
                break;
            case 4:
                tfourth();
                break;
            default:
                std::cout << "такого задания нет" << '\n';
        }
    }
}

void tfirst(){
    char yorn;
    
    do{
        
        int ans = 0;
        int m, n;
        std::cout << "n: ";
        std::cin >> n;
        std::cout << "m: ";
        std::cin >> m;
        if (m < n){
            for (int i = 5; i <= n; i+=5){
                if(i % 5 == 0 && i % m != 0){
                    ans += i;
                }
            }
            std::cout << ans << std::endl;
        }
        else{
            std::cout << "m должно быть меньше n" << std::endl;
        }
        
        std::cout << "продолжить? y/n: ";
        std::cin >> yorn;
    } while( yorn == 'y');
    
}

void tsecond(){
    double a;
    double r = 1.0;
    std::cout << "a: ";
    std::cin >> a;
    if (a >= 0){
        for (int i = 2; i <= 8; i+=2){
            r *= pow(i, 2);
        }
        r -= a;
    }
    else{
        for (int i = 3; i <= 9; i+=3){
            r *= (i - 2);
        }
    }
    std::cout << std::setprecision(14) << r << std::endl;
}

void tfourth(){
    char yorn;
    do{
        int n;
        std::cout<<"n: ";
        std::cin>>n;
        double ans = 0;
        for(int i = n; i >= 0; --i){
            ans = sqrt(ans + 2 * i + 1);
        }
        std::cout<< ans <<'\n';
        std::cout << "продолжить? y/n: ";
        std::cin >> yorn;
    } while( yorn == 'y');
}

void tthird(){
    for (double x = 0; x <= 1; x+=0.2){
        int n = 1;
        double eps = std::pow(10, -6);
        double sx = 0;
        double mmcpp = atan(x) * std::pow(x, 2);
        
        double x1 = std::pow(x, 3);
        do{
            double k = (-1) * std::pow(x, 2) * (2 * n - 1) / (2 * n + 1);
            
            sx += x1;
            x1 *= k;
            
            n++;
        }while (abs(x1) > eps);
        
        std::cout<< "x: "<< std::setw(11)<<x<<std::endl;
        std::cout<< "Y(x): " << mmcpp << std::endl;
        std::cout << "S(x): " << sx << std::endl;
        std::cout << "n: "<< std::setw(11)<<n << std::endl;
        std::cout << "" << std::endl;
    }
}

