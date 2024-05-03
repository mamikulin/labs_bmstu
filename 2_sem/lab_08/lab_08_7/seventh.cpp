#include "header.h"
// #10
// Напишите программу для 
// хранения объектов типа Point в списке (подсказка: не забудьте 
// для класса Point определить операторы < и ==)
// Создать массив точек с помощью контейнера list в main() и сразу 
// занести в него информацию о 6 точках: (1.2, 6.3), 
// (4.0, 0.7), (7.2, 0.8), (5.3, 3.0), (4.9, 6.6), (9.3, 0.2). 
// Вывести список на экран таким образом, чтобы координаты каждой 
// точки выводились в отдельной строке. Выведите на экран координаты 
// точки, которая наиболее удалена от центра координат. Сдвиньте все 
// точки влево по оси абцисс на расстояние, которое введет пользователь
// и снова выведите список на экран. Напишите функцию вывода
// списка на экран.

class Point {
public:
    double x, y;
    Point(std::string str){
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
        x = std::stod(a);
        y = std::stod(b);
        
    } 
    Point() { x = y = 0; }
    Point(double x, double y) { 
        this -> x = x; 
        this -> y = y; 
    }

    void operator=(const Point& p){
        this -> x = p.x;
        this -> y = p.y;
    }

    bool operator==(const Point& p){
        if ((this -> x == p.x) && (this -> y == p.y)){
            return true;
        }
        return false;
    }

    bool operator>(const Point& p){
        if (pow(this -> x, 2) + pow(this -> y, 2)> pow(p.x, 2) + pow(p.y, 2)){
            return true;
        }
        return false;
    }

    void operator-=(double x){
        this -> x -= x;
        
    }

    friend std::ostream& operator<<(std::ostream& out,const Point& p){

        std::cout  << "(" << p.x << ", " << p.y << ")"; 
        return out; 
    }

    friend std::ostream& operator<< (std::ostream& out, std::list<Point>& l){
        
        std::list<Point>::iterator iter;
        for(iter = l.begin(); iter != l.end(); iter++ ){
            std::cout << *iter << '\n';
        }

        return out; 
    }
};


void sort(std::list<Point>& v){
    std::list<Point>::iterator old;
    for(std::list<Point>::iterator i = v.begin(); i != v.end(); i++){
        for(std::list<Point>::iterator j = i; j != v.end(); j++){
            
            if (*i > *j){
                old = i;
                i = j;
                j = old;
            }
        }
    }
}


template <class T> 
void move(std::list<T>& v){
    int x; 
    std::cin >> x; 

    for (std::list<Point>::iterator i = v.begin(); i != v.end(); i++){
        *i -= x;
    }
}

void seventh_b(){
    std::list<Point> mass; 
    mass.push_back(Point(1.2, 6.3));
    mass.push_back(Point(4.0, 0.7));
    mass.push_back(Point(7.2, 0.8));
    mass.push_back(Point(5.3, 3.0));
    mass.push_back(Point(4.9, 6.6));
    mass.push_back(Point(9.3, 0.2));
    
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
    seventh_b();
}