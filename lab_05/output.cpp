//
//  output.cpp
//  lab_05
//
//  Created by Mike Mikulin on 12.10.2023.
//

#include "hppcommon.hpp"

void output(int* mass, int changes, int comper, int len){
    char y_or_n = 'n';
    std::cout << "вывести отсортированный массив? y/n ";
    std::cin >> y_or_n;
    
    if (y_or_n == 'y'){
        std::copy ( mass, mass + len, std::ostream_iterator<int>(std::cout, ", ") );
        std::cout << '\n';
    }
    
    
    std::cout << "сравнения: "  <<  comper << std::endl;
    std::cout << "перестановки: "  << changes << std::endl;
}
