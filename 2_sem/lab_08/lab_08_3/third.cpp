#include "header.h"
// #18
// Дан текстовый файл. Запишите в другой файл только
// такие строки исходного файла,
// если они начинаются с цифры.

bool first_is_int(std::string a){
    for(int i = 0; i < 10; i++){
        if(int(*(a.begin())) == i+48){
            return true;
        }
    }
    return false; 

}


void third_b(){
    std::fstream a("a_third.txt");
    std::fstream b("b_third.txt");
    int c = 0; 
    std::string str;

    while(std::getline(a, str)){
        c++;
    }
    a.clear();
    a.seekg(0);
    
    for(int i = 0; i < c; i++){
        std::getline(a, str);
        if (first_is_int(str)){

            b << str << '\n';
        }
    }

    a.close();
    b.close();
}

int main(){
    third_b();
    return 0;
}