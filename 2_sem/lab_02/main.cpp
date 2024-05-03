#include "team/team.h"

#include <iostream>



int main() {
    int S = 2;
    int& Size = S;
    int c = 0 ;
    int& amount = c;
    Worker* mass = new Worker[Size];
    read_db("data.txt", mass, amount, Size);
   
    while (true) {
        
        switch (menu()) {
            case 1:
                if (amount == Size){
                    std::cout<< '\n' << Size << '\n';
                    extend(mass, Size, Size * 2);
                    Size = Size * 2;
                }
                createnew(mass, amount);
                break;
            case 2:
                edit(mass, amount);
                break;
            case 3:
                deletewo(mass, amount);
                break;
            case 4:
                sort_db(mass, amount);
                break;
            case 5:
                write_db("data.txt", mass, amount);
            case 6:
                print_db(mass, amount);
                break;
            case 7:
                delete[] mass;
                return 0;
            default:
                std::cout << "Введен некорректный запрос\n";
                break;
        }
    }
}