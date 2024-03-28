#include "fraction.h"

int fraction::nod(int a, int b) {
    
    if (a == b){
        return a;
    }
    if (a > b){
        return nod(a-b, b);
    }
    return nod(a, b-a);
}

void fraction::priv(){
    if (denominator_ != 1){
        int d = nod(abs(numerator_), abs(denominator_));
        numerator_ /= d;
        denominator_ /= d;
    }
}

std::istream& operator>>(std::istream& in, fraction &f){
    char input[50];
    in.getline(input, 50);
    int znak = 1; 
    int c = 0; 
    int space = -1, line = -1;

    char main_p[16], numerator[16], denominator[16];

    while(input[c] != '\0'){
        if(input[c] == ' '){
            space = c; 
        }else if(input[c] == '/'){
            line = c;
        }
        if( input[c] == '-'){
            znak = -1;
        }
        c++;
    }
    
    for(int i = 0; i < space; i++){
        main_p[i] = input[i];
        main_p[i+1] = '\0';
    }
    
    for(int i = space+1; i < line; i++){
        numerator[i - (space + 1)] = input[i];
        numerator[i - (space + 1) + 1] = '\0';
    }
    for(int i = line+1; i < c; i++){
        denominator[i - (line + 1)] = input[i];
        denominator[i - (line + 1) + 1] = '\0';
    }



    if (line == -1){
        f.set_numerator(atoi(denominator));
        f.set_denominator(1);

        return in;
    }if (atoi(denominator) != 0){
        f.set_numerator(abs(atoi(main_p)) * atoi(denominator) + abs(atoi(numerator)));
        
        f.set_numerator(f.get_numerator() * znak);
        
        f.set_denominator(atoi(denominator));

        return in;
    }
    
    std::cout << "Error denominator = 0" << '\n';

    return in; 
}

std::ostream& operator<<(std::ostream& out, fraction &f){
    f.priv();
    if( f.get_numerator() / f.get_denominator() != 0 ){
        if(f.get_numerator() % f.get_denominator() != 0){
            std::cout << f.get_numerator() / f.get_denominator() << ' ' << abs(f.get_numerator()) % f.get_denominator() << '/' << f.get_denominator() << '\n';
        }else{
            std::cout << f.get_numerator() / f.get_denominator()<< '\n';
        }
    }else{
        std::cout << f.get_numerator() << '/' << f.get_denominator() << '\n';
    }
    return out;
}

fraction::fraction(const char* input_ptr){
    char input[50];
    int znak = 1; 
    strcpy(input, input_ptr);
    int c = 0; 
    int space = -1, line = -1;

    char main_p[16], numerator[16], denominator[16];

    while(input[c] != '\0'){
        if(input[c] == ' '){
            space = c; 
        }else if(input[c] == '/'){
            line = c;
        }
        if( input[c] == '-'){
            znak = -1;
        }
        
        c++;
    }
    
    for(int i = 0; i < space; i++){
        main_p[i] = input[i];
        main_p[i+1] = '\0';
    }
    
    for(int i = space+1; i < line; i++){
        numerator[i - (space + 1)] = input[i];
        numerator[i - (space + 1) + 1] = '\0';
    }
    for(int i = line+1; i < c; i++){
        denominator[i - (line + 1)] = input[i];
        denominator[i - (line + 1) + 1] = '\0';
    }
    
    if (line == -1){
        this -> set_numerator(atoi(denominator));
        this -> set_denominator(1);

        return;
    }if (atoi(denominator) != 0){
        this -> set_numerator(abs(atoi(main_p)) * atoi(denominator) + abs(atoi(numerator)));
        this -> set_numerator(this -> get_numerator() * znak);
        this -> set_denominator(atoi(denominator));

        return;
    }
    
    std::cout << "Error denominator = 0" << '\n';

    return ; 


}

fraction::fraction( int numerator, int denominator)
{
    this -> set_numerator(numerator);
    this -> set_denominator(denominator);
    
}

fraction::fraction(const double znach){
    
    double mp = std::floor(znach);
    double sp = znach - mp;
    int eps = pow(10, 6);
    this -> set_numerator(mp * eps + sp * eps); 
    this -> set_denominator(eps);
}

//fraction::fraction( int znach){
 //   std::cout<<" int const"<<znach<<'\n';
  //  this -> set_numerator(znach);
   // this -> set_denominator(1);
//}




int fraction::get_numerator(){
    return numerator_;
}

int fraction::get_denominator(){
    return denominator_;
}

void fraction::set_numerator(int numerator){
    numerator_ = numerator;
}

void fraction::set_denominator(int denominator){
    denominator_ = denominator;
}

fraction operator+(const fraction& a, const fraction& b){
   
    int numerator = (a.numerator_ * b.denominator_) + (a.denominator_ * b.numerator_);
    int denominator =  a.denominator_ * b.denominator_;

    return fraction(numerator ,denominator);
}

fraction operator+(const double& a, const fraction& b){
    fraction elm_f(a);
    return b + elm_f;
}

fraction operator+(const fraction& a, const double& b){
    fraction elm_f(b);
    return a + elm_f;
}

// fraction fraction::operator+(fraction& elm){
//     std::cout << "first" << '\n';
//     int numerator = (this -> numerator_ * elm.get_denominator()) + (this -> denominator_ * elm.get_numerator());
//     int denominator =  this -> denominator_ * elm.get_denominator();
//     return fraction(numerator ,denominator);
// }

fraction fraction::operator+(int& elm){
    fraction elm_f(elm);
    return *this + elm_f;
}

// fraction fraction::operator+(double& elm){
//     fraction elm_f(elm);
//     return *this + elm_f;
// }



