#include "header.h"
// #10
// Создайте два вектора для хранения имен абонентов и их 
// телефонных номеров. Имена и номера телефонов должны 
// вводиться пользователем. После окончания ввода распечатать 
// имена и телефонные номера абонентов в виде строк: имя абонента – 
// его номер. Выполнить поиск номера по имени абонента. Удалите 
// найденный номер и имя абонента из векторов. Снова распечатайте векторы. 
// Переделать программу: печатать векторы с помощью функции.

void add(std::vector<std::string> &names, std::vector<std::string> &phones){
    std::string str; 
    std::cout << "имя: "; 
    std::cin >> str; 
    names.push_back(str);
    std::cout << "телефон: "; 
    std::cin >> str; 
    phones.push_back(str);

    std::cout << '\n';
}

int find(std::vector<std::string> &names, std::string search){
    for(int i = 0; i < names.size(); i++){
        if (search == names[i]){
            return i; 
        }
    }
    return -1; 
    
}

void delete_a(std::vector<std::string> &names, std::vector<std::string> &phones){
    std::string name_d; 
    std::cout << "удалить: ";
    std::cin >> name_d;
    auto index = find(names.begin(), names.end(), name_d);
    int id = index - names.begin(); 
    names.erase(names.begin() + id);
    phones.erase(phones.begin() + id);

    std::cout << '\n';

}

void print(std::vector<std::string> &names, std::vector<std::string> &phones){
    for(int i = 0; i < names.size(); i++){
        std::cout << names[i] << " - " << phones[i] << '\n';
    }
    std::cout << '\n';
}

void fourth_b(){
    std::vector<std::string> names, phones; 

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
    fourth_b();
    return 0; 
}