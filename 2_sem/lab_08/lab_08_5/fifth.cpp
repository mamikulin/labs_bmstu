#include "header.h"
// #10 
// Напишите программу для хранения объектов 
// типа Graduate в векторе (подсказка: не забудьте для класса 
// Graduate определить операторы < и ==).
class Graduate {
public:
    std::string name;    // фамилия
    double rating;  // рейтинг
    Graduate(std::string str){
        std::vector<int> n; 
        std::string a, b;
        bool pre = false; 
        for(int i = 0; i < str.length(); i++){
            if (str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ','  || str[i] == '.'){
                pre = false;
            }else if(pre == false){
                n.push_back(i);
                pre = true;
            }
            
        }

        for(int i = n[0]; i <= n[1]; i++){
            a += str[i];
        }
        for(int i = n[2]; i <= n[3]; i++){
            b += str[i];
        }
        name = a;
        rating = std::stod(b);
        
    } 
    Graduate() { name = rating = 0; }
    Graduate(std::string name, double rating) { 
        this -> name = name; 
        this -> rating = rating; 
    }

    void operator=(const Graduate& g){
        this -> name = g.name;
        this -> rating = g.rating;
    }

    bool operator==(const Graduate& g){
        if ((this -> name == g.name) && (this -> rating == g.rating)){
            return true;
        }
        return false;
    }

    bool operator>(const Graduate& g){
        if (this -> rating> g.rating){
            return true;
        }
        return false;
    }

    void operator+=(double x){
        this -> rating += x;
        
    }

    friend std::ostream& operator<<(std::ostream& out,const Graduate& p){

        std::cout  << p.name << ", " << p.rating; 
        return out; 
    }

    friend std::ostream& operator<< (std::ostream& out, std::vector<Graduate>& v){
        
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i] << '\n';
        }

        return out; 
    }
};

template <class T> 
void sort(std::vector<T>& v){
    T old;
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){

            if (v[i] > v[j]){
                old = v[i];
                v[i] = v[j];
                v[j] = old;
            }
        }
    }
}


template <class T> 
void move(std::vector<T>& v){
    int x; 
    std::cin >> x; 

    for (int i = 0; i < v.size(); i++){
        v[i] += x;
    }
}

void fifth_b(){
    std::vector<Graduate> mass; 
    mass.push_back(Graduate("Иванов", 99));
    mass.push_back(Graduate("Петров", 430));
    mass.push_back(Graduate("Семенов", 70));
    mass.push_back(Graduate("Котов", 540));
    mass.push_back(Graduate("Черных", 350));
    
    std::cout << mass;

    std::cout << '\n';
    std::cout << '\n';
    sort(mass);
    std::cout << mass;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << mass.back() << '\n'; 
    std::cout << '\n';
    std::cout << '\n';
    move(mass);
    std::cout << mass;
}

int main(){
    fifth_b();
}