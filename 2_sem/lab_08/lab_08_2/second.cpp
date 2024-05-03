#include "header.h"
// #18
//Пользователь вводит некоторый текст. 
//Образовать из него новый, в который включить информацию, 
//заключенную между первым пробелом и первой точкой.

void second_b(){
    std::string str;
    getline(std::cin, str);
    bool space = false;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' '){
           space = true;  
        }

        if (space == true){
            std::cout << str[i];
        }

        if (space == true && str[i] == '.'){
            std::cout << '\n';
            break;
        }
    }

}
int main(){
    second_b();
    return 0;
}