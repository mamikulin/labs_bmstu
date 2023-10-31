#include <iostream>
#include <math.h>

struct returnans {
    double root;
    int n;
};

double func(double x, int k);

returnans newton(int k, double eps);
returnans binary(int k, double eps);
returnans iterations(int k, double eps);

int main() {
    returnans ansbin, ansnew, ansiter;
    int k, power;
    while (true){
       
        std::cout << "power: ";
        std::cin >> power;
        double eps = pow(10, power);
        std::cout << "k: ";
        std::cin >> k;
        std::cout << "0" << std::endl;
        ansbin = binary(k, eps);
        std::cout << "1" << std::endl;
        ansnew = newton(k, eps);
        std::cout << "2" << std::endl;
        ansiter = iterations(k, eps);
        
        std::cout << ansbin.root << " " << ansbin.n << std::endl;
        
        std::cout << ansnew.root << " " << ansnew.n << std::endl;
        
        std::cout << ansiter.root << " " << ansiter.n << std::endl;
        
        
        
    }
}

double func(double x, int k){
    double y = x - k * std::cos(x);
    return y;
}

returnans iterations(int k, double eps){
    returnans iterationsans;
    double razn = 1;
    int n = 1;
    
    double x = -1 * k;
    
    while (std::abs(razn) >= eps){
        razn = k * std::cos(x) - x;
        
        x = k * std::cos(x);
        n ++;
        
    }
    
    iterationsans.root = x;
    iterationsans.n = n;
    
    return iterationsans;
}


returnans newton(int k, double eps){
    returnans newtonsr;
    double razn = 1;
    
    int n = 0;
    
    double x = -1*k;
    while (std::abs(razn) >= eps){
        
        razn = x - (x - func(x, k) / (1 + k * std::sin(x)));
        x = x - func(x, k) / (1 + k * std::sin(x));
        n ++;
    }
    
    newtonsr.root = x;
    newtonsr.n = n;
    
    return newtonsr;
}

returnans binary(int k, double eps){
    returnans binaryans;
    double x1 = -1 * k;
    double x2 = k;
    double xp = 0;
    int n = 0;
    
    while (x2 - x1 > eps){
        if (func(x1, k) * func(x2, k) < 0){
            xp = x1;
            x1 = (x1 + x2)/2;
        }
        else{
            x2 = x1;
            x1 = xp;
            
        }
        n ++;
        
    }
    
    binaryans.root = x2;
    binaryans.n = n;
    
    return binaryans;
}


