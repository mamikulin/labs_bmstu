#include "header.h"


int main(){
    Term a, b, c;
    Polynomial abc, cbc, cnn, bbc, buff; 
    // std::cin >> a; 
    // std::cout << a; 

    std::cin >> abc;
    std::cin >> cbc;

    std::cout << "\n\n1:"<< std::setw(14)<< abc << '\n';
    std::cout << "2:"<< std::setw(14)<<cbc << '\n';
    cnn = abc + cbc; 
    bbc = abc * cbc;
    buff = abc;
    abc += cbc;
    std::cout <<"1 += 2:" << std::setw(10)<< abc << " " <<'\n';
    std::cout <<"3 = 1+ 2:"<< std::setw(8)<< cnn << '\n';
    buff *= cbc;
    std::cout <<"1 *= 2:"<< std::setw(13)<< buff << '\n';
    std::cout << "4 = 1 * 2:"<< std::setw(10)<< bbc << " "<< '\n';
    return 0;
}