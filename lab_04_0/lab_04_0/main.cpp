#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>

#include "iterations.hpp"
#include "binary.hpp"
#include "newton.hpp"

#include "struct_returnans.hpp"

int main() {
    while (true){
        returnans ansbin, ansnew, ansiter;
        int k, power;
        
        std::cout << "power: ";
        std::cin >> power;
        double eps = pow(10, power);
        std::cout << "k: ";
        std::cin >> k;
        
        ansbin = binary(k, eps);
        ansnew = newton(k, eps);
        ansiter = iterations(k, eps);
        
        std::cout  << std::setprecision(10)<< "Метод половинного деления" <<  std::setw(15) << ansbin.root << std::setw(10) << ansbin.n << std::endl;
        std::cout << std::setprecision(10)<< "Метод Ньютона" <<  std::setw(27) << ansnew.root << std::setw(10) << ansnew.n << std::endl;
        std::cout << std::setprecision(10)<< "Простая итерация" <<  std::setw(24) << ansiter.root << std::setw(10) << ansiter.n << std::endl;
        std::cout << "______________________________________________" << std::endl;
        
    }
}




