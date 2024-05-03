#include "header.h"

// #10
// Создайте два контейнера для хранения имен абонентов и и
// их телефонных номеров. Имена и номера телефонов должны вводиться 
// пользователем. После окончания ввода распечатать имена и 
// телефонные номера абонентов в виде строк: имя абонента – его номер.
//  Выполнить поиск номера по имени абонента.
//  Удалите найденный номер и имя абонента из контейнеров. 
// Снова распечатайте контейнеры. Переделать программу: печатать
//  контейнеры с помощью функции.


void delete_a(std::list<std::string>& names, std::list<std::string>& phones){
    std::string name_d; 
    std::cout << "удалить: "; 
    std::cin >> name_d;
    
    auto index = find(names.begin(), names.end(), name_d);
    
    
    auto it_p = phones.begin();
    for(auto it = names.begin(); it != index; it++){
        
        it_p++;
    }

    names.erase(index);
    phones.erase(it_p);

    // int id = find(l, name_d);
    // if (id == -1){
    //     return ;
        
    // }
    // std::list<Abonent>::iterator iter = l.begin();
    // for(int i = 0; i < id; i++){
    //     iter++;
    // }
    // l.erase(iter);
    // std::cout << '\n';
}

void add(std::list<std::string>& names, std::list<std::string>& phones){
    std::string name, phone; 
    std::cout << "имя: "; 
    std::cin >> name ; 
    
    std::cout << "телефон: "; 
    std::cin >> phone; 

    names.push_back(name);
    phones.push_back(phone);
    
}

void print(std::list<std::string> &names, std::list<std::string> &phones){
    auto id_n = names.begin();
    auto id_p = phones.begin();
    for(int i = 0; i < names.size(); i++){
        std::cout << *id_n << " - " << *id_p << '\n';
        id_n++; 
        id_p++; 
    }
    std::cout << '\n';
}

void sixth_b(){
    std::list <std::string> names; 
    std::list <std::string> phones; 

    for(int i = 0; i < 5; i++){
        std::cout << i+1 << "/5\n";
        add(names, phones);
    }

    print(names, phones);
    delete_a(names, phones);
    delete_a(names, phones);

    print(names, phones);
}

int main(){
    sixth_b();
    return 0;
}