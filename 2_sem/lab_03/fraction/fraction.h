#include <iostream> 
#include <fstream>
#include <cmath>

#pragma once

class fraction{
    private:
        int numerator_;
        int denominator_;
    
        int nod(int, int);

        void priv();

        friend std::istream& operator>>(std::istream&, fraction&);
        friend std::ostream& operator<<(std::ostream&, fraction&);

    public:
        fraction(const int,const int);
        fraction(){
            numerator_ = 0; 
            denominator_ = 0;
        };
        fraction(const int);
        fraction(const double);
        fraction(const char*);

        void operator=(const fraction& elm){
            this -> set_numerator(elm.numerator_);
            this -> set_denominator(elm.denominator_);
        }

        int get_numerator();
        int get_denominator();
        void set_numerator(int );
        void set_denominator(int );

        friend fraction operator+(const fraction&, const fraction&);
        friend fraction operator+(const double& a, const fraction& b);
        friend fraction operator+(const fraction& a, const double& b);

        fraction operator+(double&);
        fraction operator+(fraction& );
        fraction operator+(int&);

        // fraction& fraction::operator+=(const fraction& elm);
        // fraction& fraction::operator+=(const int& elm);
        // fraction& fraction::operator+=(const double& elm);
        fraction& operator+=(const fraction& elm){
            fraction summ = *this + elm;
            *this = summ; 
            return *this;
        }
        fraction& operator+=(const int& elm){
            fraction elm_f(elm);
            *this += elm_f;
            return *this;
        }
        fraction& operator+=(const double& elm){
            fraction elm_f(elm);
            *this += elm_f;
            return *this;
        }



};

