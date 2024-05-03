#include "header.h"
// #10
// Создайте отображение map<int, double> и занесите в него пары 1 – 100.0, 2 – 200.0, 3 – 300.0, ..., 9 – 900.0. 
// Выведите содержимое отображения на экран. Вычислите сумму значений в 
// контейнере. Каждое значение разделите на полученную сумму и вновь 
// выведите отображение.
template <class T, class T1> 
void print(std::map<T, T1>& m){
    typename std::map<T, T1>::iterator i; 
    for(i = m.begin(); i != m.end(); i++){
        std::cout << i -> first << " - " << i -> second << '\n';
    }
}
template <class T, class T1> 
void summ_and_div(std::map<T, T1>& m){
    double r;
    typename std::map<T, T1>::iterator i; 
    for(i = m.begin(); i != m.end(); i++){
        r+= i -> second;
    }
    std::cout << r << '\n';
    for(i = m.begin(); i != m.end(); i++){
        i -> second /= r;
    }
    
}

void eight(){
    std::map<int, double> m; 
    for(int i = 1; i < 10; i++){
        m[i] = i * 100.0;
    }

    print(m);

    std::cout << '\n';
    std::cout << '\n';

    summ_and_div(m);
    
    print(m);

}


int main(){ 
    eight();
    return 0; 
}