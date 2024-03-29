// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.


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