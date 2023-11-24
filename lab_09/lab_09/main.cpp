//
//  main.cpp
//  lab_09
//
//  Created by Mike Mikulin on 09.11.2023.
//
#include <iostream>
#include <fstream>

char input();

int main() {
    std::fstream getword;
    getword.open("dic.txt");
    
    if (!getword.is_open()){
        exit(0);
    }
//    char abc;
//    char* def = "abc";
//    int count = 0;
//    std::cout << &def;
   
//    for (getword>>abc;!getword.eof();getword>>abc){count++;}
//    std::cout << def;
//    for (int i =0; i<11; i++){
//        getword >> abc;
//        if (abc != ' '){
//            *(&def + i) = abc;
//        }else{
//            break;
//        }
//    }
    
    char* in[10], c;
    in = &input();
//    std::cout << *(in+2) << '\n';
    for(int i = 0;*(in ) != '\0';i++){
        c = *(in + i) ;
        std::cout << c;
    }
    std::cout << '\n';
    getword.close();
    return 1;
}


char input(){
    char *input_ptr = nullptr, input[10], c;
    std::cin >> input;
    
//    for(int i = 0;input[i] != '\0';i++){
//        c = input[i];
//        std::cout << c;
//    }
//    input_ptr = &input;
    
    return input;
}
