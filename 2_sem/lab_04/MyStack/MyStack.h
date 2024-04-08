// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.

#include <iostream>
#ifndef MyStack_h                       // защита от повторной компиляции
#define MyStack_h                       // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode                          // узел списка
{
private:
    INF d;                              // информационная часть узла
    ListNode *next;                     // указатель на следующий узел списка
    ListNode(void) { next = nullptr; }  //конструктор
    // ListNode(ListNode& a) { 
    //     this -> next = a.next;
    //     this -> d = a.d;
    //  } 
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void){
        top = nullptr;
    }           // конструктор
    

    MyStack& operator=(const MyStack& stack){
        MyStack<INF> stack_r;
        auto top_s = stack.top;
        
        while(!(this->empty())){
            this -> pop();
        }  
        while(!(top_s == nullptr)){
            stack_r.push(top_s->d);
            top_s = top_s -> next;
        }

        while(!stack_r.empty()){
            this -> push(stack_r.top_inf());
            stack_r.pop();
        }
        return *this;
    }

    MyStack(const MyStack& stack){
        top = nullptr;

        *this = stack;
        
    }

    ~MyStack(void){
        while(!empty()){
            pop();
        }
        delete top;
    }          // освободить динамическую память

    bool empty(void){
        if (top != nullptr){
            return false;
        }
        return true;
    }        // стек пустой?
    
    void push(INF n){
        Node* new_elm = new Node;
        new_elm -> d = n;
        new_elm -> next = top;
        
        top = new_elm;
    }        // добавить узел в вершину стека

    void pop(void){
        
        if(!empty()){

            Node* del = top;
            // std::cout << top << '\n';
            top = top -> next;
            delete del; 
        }else{
            top = nullptr;
        }
    }          // удалить узел из вершины стека

    INF top_inf(void){
        // std::cout << top -> next << '\n';
        if (!empty()){
            return top->d;
        }
    }       // считать информацию из вершины стека

    

};

#endif