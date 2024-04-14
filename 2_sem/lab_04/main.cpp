#include "MyStack/MyStack.h"
#include <iostream>


void Multipliers(int n, MyStack<int> &stack){
    int i = 2; 
    while(i <= n){
        while(n % i == 0){
            stack.push(i); 
            n /= i;
        }
        i++; 
    }
}


int main(){

    MyStack<int> stack;
    MyStack<int> stack_r, stack_a;
    
    int N = 3960;

    Multipliers(N, stack);
    std::cout << N << " =";
    while(!stack.empty()){
        std::cout << " " << stack.top_inf();
        stack_r.push(stack.top_inf());
        stack.pop();
        if(!stack.empty()){
            std::cout << " *";
        }
    }
    std::cout << '\n';

    
    stack_a = stack_r;
    MyStack<int> stack_b(stack_r); //проверка конструктора копирования
    std::cout << N << " =";
    while(!stack_r.empty()){
        std::cout << " " << stack_r.top_inf();
       
        stack_r.pop();
        if(!stack_r.empty()){
            std::cout << " *";
        }
    }
    std::cout << '\n';


    

    
    return 0; 


}