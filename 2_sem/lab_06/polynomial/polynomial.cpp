#include "polynomial.h"

int Term::cw(char* s, Term& a){
    char coefficient[128], power[128];
    int i = 0;
    int r = -1; 
    int x = -2, len = 0;
    bool ok = false;
    while(s[i] != '\0'){
        if((s[i] == '+' || s[i] == '-') && i != 0 && i != x+2){
            r = i;
            break;
        }
        if(s[i] == 'x'){
            x = i;
        }
        if(s[i] == '^'){
            ok = true;
        }

        i++;
        len++;
    }
    
    if(x == -2){
        x = len;
    }
    for(int i = 0; i < x; i++){
        coefficient[i] = s[i];
    }

    coefficient[x]  = '\0';

    if (ok){
        for(int i = x+2; i < len; i++){
            power[i-(x+2)] = s[i];
        }
        power[i-(x+2)] = '\0';
    }
    if (s[x-1] != '-'){
        if (s[x-1]  != '+'){
            a.coefficient = atoi(coefficient);
        }else{
            a.coefficient = 1;
        }
    }else{
        a.coefficient = -1;
    }
    if (ok){
        a.power = atoi(power);
    }else{
        a.power = 0;
    }

    if(x+1 == len){
        a.power = 1;
    }
    if(x == 0){
        a.coefficient = 1;
    }


    return r;
}

Term operator+(const Term& a, const Term& b){
    int coefficient = 0;
    if (a.power == b.power){
       coefficient = a.coefficient + b.coefficient;
    }

    return Term(coefficient, a.power);
}
int f = 0;
std::ostream& operator<<(std::ostream& out, Term &a){
    
    if (a.coefficient != 1 && a.coefficient != 0){
        if(a.coefficient > 0){
            if (f){
                
                std::cout << "+ ";
                
            }
            f++;
            if(a.power != 1 && a.power != 0){
                std::cout << a.coefficient << "x^" << a.power ;
            }else if(a.power == 1){
                std::cout << a.coefficient << "x";
            }else{
                std::cout << a.coefficient;
            }
        }else{
            if(a.power != 1 && a.power != 0){
                std::cout << a.coefficient << "x^" << a.power ;
            }else if(a.power == 1){
                std::cout << a.coefficient << "x";
            }else{
                std::cout << a.coefficient;
            }
        }
    }else if(a.coefficient == 1){
        if(a.power != 1 && a.power != 0){
            std::cout << "x^" << a.power;
        }else if(a.power == 1){
            std::cout << "x ";
        }else{
            std::cout << a.coefficient;
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, Term &a){
    
    char* input = new char[16];
    in.getline(input, 16);
    int n;
    n = a.cw(input, a);
    delete[] input;
    return in;
}

std::ostream& operator<<(std::ostream& out, Polynomial& a){
    
    for(int i = 0; i < a.degree; i++){
        if (a.poly[i].get_coefficient() != 0){
            std::cout << a.poly[i] << " ";
        }
    }

    f = 0;


    return out;

}

std::istream& operator>>(std::istream& in, Polynomial& a){
    
    char input[128];
    in.getline(input, 128);
 
    int i = 0, k = 0, degree = 1; 
    char* pol = new char[128];
    
    while(input[i] != '\n' && input[i] != '\0'){
        if (input[i] != ' '){
            pol[k] = input[i]; 
            k++;
        }if(input[i] == '+' || input[i] == '-' ){
            degree++;
        }
        i++;   
    }
    int len = i;
    Term* mass = new Term[degree];
    int cut = 0;
    for(int i = 0; i < degree; i++ ){
        for(int j = cut; j < len; j++){
            pol[j-cut] = pol[j];
        
        }

        pol[len-cut] = '\0';
        cut = mass[i].cw(pol, mass[i]);
        
    }
    a.degree = degree; 
    a.poly = mass;
    return in;
}

void Polynomial::shape(){
    for(int i = 0 ; i < this -> degree-1; i++){
        for(int j = i+1; j < this -> degree; j++){
            if (poly[i].power == poly[j].power){
                poly[i] = poly[i] + poly[j];
                poly[j].coefficient = 0;
                poly[j].power = 0;
            }
        }
    }

    
    Term buff;
    if (order_ == -1){
    for (int i = 0; i < degree - 1; i++) {
        for (int j = 0; j < degree - i - 1; j++) {
            if (poly[j].power > poly[j+1].power) {
                buff = poly[j];
                poly[j] = poly[j + 1];
                poly[j + 1] = buff;
                }
            }
        }
    }else{
        for (int i = 0; i < degree - 1; i++) {
        for (int j = 0; j < degree - i - 1; j++) {
            if (poly[j].power < poly[j+1].power) {
                buff = poly[j];
                poly[j] = poly[j + 1];
                poly[j + 1] = buff;
                }
            }
        }
    }
}

Polynomial operator+(const Polynomial& a, const Polynomial& b){
    Polynomial r;
    int degree = a.degree + b.degree; 
    int c;
    Term* poly= new Term[degree];

    for(int i = 0; i < a.degree; i++){
        poly[i] = a.poly[i];
        c = i;
    }
    
    for(int i = 0; i < b.degree; i++){
        poly[i+c] = b.poly[i];
        
    }
    r.poly = new Term[degree];
    for (int i = 0; i < degree; i++){
        r.poly[i] = poly[i];
    }
    r.degree = degree; 
    
    r.shape();


    return r; 
}
Polynomial operator*(const Polynomial& a, const Polynomial& b){
    Polynomial r;
    int c = 0;
    int degree = a.degree * b.degree ; 
    Term* poly= new Term[degree];

    for(int i = 0; i < a.degree; i++){
        for(int j = 0; j < b.degree; j++){
            poly[i+j + (i*j)].set_coefficient(a.poly[i].get_coefficient()*b.poly[j].get_coefficient());
            poly[i+j + (i*j)].set_power(a.poly[i].get_power()+b.poly[j].get_power());
        }
        
    }
    r.poly = new Term[degree];
    for (int i = 0; i < degree; i++){
        r.poly[i] = poly[i];
        
    }
    r.degree = degree; 
    r.shape();
    
    return r;
}


