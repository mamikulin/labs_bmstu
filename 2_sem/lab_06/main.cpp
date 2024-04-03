#include "header.h"


int main(){
    Term a, b, c;
    Polynomial abc, cbc, cnn, bbc; 
    // std::cin >> a; 
    // std::cout << a; 

    std::cin >> abc;
    std::cin >> cbc;
    cnn = abc + cbc; 
    bbc = abc * cbc;

    abc *= cbc;

    std::cout << abc << '\n';

    std::cout << cnn << '\n';
    std::cout << bbc << '\n';
    return 0;
}