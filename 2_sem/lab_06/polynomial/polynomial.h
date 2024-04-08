#include <fstream>
#include <iostream>

#pragma once


class Term{
private:
    
    int coefficient;                             
    int power;


    friend std::ostream& operator<<(std::ostream&, Term&);
    friend std::istream& operator>>(std::istream&, Term&);
    
public:
    Term(int coefficient = 0, int power = 0){
        
        this -> coefficient = coefficient; 
        this -> power = power;
    }

    int cw(char*, Term&);

    friend Term operator+(const Term&, const Term&);
    void operator=(const Term& a){
        this->coefficient = a.coefficient;
        this->power = a.power;
    }
    int get_coefficient(){return coefficient;}
    int get_power(){return power;}
    void set_coefficient(int coefficient){
        this -> coefficient = coefficient;
    }
    void set_power(int power){
        this -> power = power; 
    }
    friend class Polynomial;

};


class Polynomial{
    private: 

        Term* poly;
        
        
        int order_;

        friend std::ostream& operator<<(std::ostream&, Polynomial&);
        friend std::istream& operator>>(std::istream&, Polynomial&);

    public: 
        int degree;
        void shape();
        
        Polynomial(int degree = 0){
            this -> order_ = 1; // max -> min: 1; min -> max: -1
            this -> degree = degree;
            this -> poly= new Term[1];
        }
        ~Polynomial(){
            delete[] poly;
        }

        friend Polynomial operator+(const Polynomial&, const Polynomial&);
        friend Polynomial operator*(const Polynomial&, const Polynomial&);

        Polynomial(Polynomial &a){
            this->degree = a.degree;
            this -> poly = new Term[degree];
            for (int i = 0; i < a.degree; i++){
                this -> poly[i] = a.poly[i];
            }

        }


        Polynomial& operator=(const Polynomial& a){
            this->degree = a.degree;
            delete[] this->poly;
            this -> poly = new Term[degree];
            for (int i = 0; i < this->degree; i++){
                
                this -> poly[i] = a.poly[i];
                
            }
            
            return *this;
         }

        Polynomial& operator+=(const Polynomial& a){
            Polynomial r = *this + a;
            *this = r; 
            return *this;
        }
        Polynomial& operator*=(const Polynomial& a){
            Polynomial r = *this * a;
            
            *this = r; 
            return *this;
        }
        
};
