#include "header.hpp"

void read_db(char* filename){
    char ch;
    int len = 0;
    
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()){
        std::cout << "файл не найден" << '\n';
        exit(404);
    }
    
    for (file>>ch; !file.eof(); file>>std::noskipws>>ch){
        len++;
    }
    
    std::cout << len << '\n';
    
    
}
