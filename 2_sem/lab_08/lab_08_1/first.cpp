#include "./header.h"
// #18
// Пользователь вводит 3 слова в 3-х разных переменных.
// Образовать новую последовательность символов, 
// состоящую из первых букв каждого слова (слитно без пробелов).


void first_b(){
    std::vector<std::string> Vect;

    std::string a, b, c; 
    std::string ans; 

    std::cin >> a >> b >> c;
    Vect.push_back(a); 
    Vect.push_back(b); 
    Vect.push_back(c); 


    for (int i = 0; i < Vect.size(); i++){
        ans.push_back(*Vect[i].begin());
    }
    std::cout << ans << '\n';

}


int main(){
    first_b(); 
    return 0;
}
