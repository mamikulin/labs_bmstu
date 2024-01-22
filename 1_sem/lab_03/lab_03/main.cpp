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
double y(int n);

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
    int ans;
    int m, n;
    do{
        ans = 0;
        
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
    int n;
    double ans = 0;
    do{
        
        std::cout<<"n: ";
        std::cin>>n;
        
        std::cout << "n = 3: " << y(3) << '\n';
        std::cout << "n = 5: " << y(5) << '\n';
        std::cout << "n = 10: " << y(10) << '\n';
        
        ans = y(n);
        
        std::cout<< ans <<'\n';
        
        
        std::cout << "продолжить? y/n: ";
        std::cin >> yorn;
    } while( yorn == 'y');
}

double y(int n)
{
    double ans;
    for(int i = n; i >= 0; --i){
        ans = sqrt(ans + 2 * i + 1);
    }
    
    return ans;
}

void tthird(){
    double sx, eps, mmcpp;
    int n;
    for (double x = 0; x <= 1; x+=0.2){
        n = 1;
        eps = std::pow(10, -6);
        sx = 0;
        mmcpp = atan(x) * std::pow(x, 2);
        
        double x1 = std::pow(x, 3);
        do{
            double k = (-1) * std::pow(x, 2) * (2 * n - 1) / (2 * n + 1);
            
            sx += x1;
            x1 *= k;
            
            n++;
        }while (abs(x1) > eps);
        
        std::cout<< "x: "<< std::setw(11)<<x<<std::endl;
        std::cout<< "Y(x): " << std::setw(3) << mmcpp << std::endl;
        std::cout << "S(x): " << std::setw(3)<< sx << std::endl;
        std::cout << "n: "<< std::setw(11)<<n << std::endl;
        std::cout << "" << std::endl;
    }
}

