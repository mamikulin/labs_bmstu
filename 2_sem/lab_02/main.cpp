#include "team/team.h"

#include <iostream>



int main() {
    int Size = 4;
    int c = 0 ;
    int& amount = c;
    Worker* mass = new Worker[Size];
    read_db("data.txt", mass, amount);
    while (true) {
        if (amount == Size){
            std::cout << Size << '\n';
            extend(mass, Size, Size * 2);
            Size = Size * 2;
        }
        switch (menu()) {
            case 1:
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
                return 0;
            default:
                std::cout << "Введен некорректный запрос\n";
                break;
        }
    }
}

//
//int main(){
//    int c = 0, k;
//    Planet* mass = new Planet[Size];
//    int& amount = c;
//    read_db("data.txt", mass, amount);
//    mass[0].print();
//    // print_db(mass, amount);
//    // createnew(mass, amount);
//    // print_db(mass, amount);
//    // deletepl(mass, amount);
//    // print_db(mass, amount);
//    // edit(mass, amount);
//    // sort_db(mass, amount);
//    print_db(mass, amount);
//    // find(mass, amount);
//    // print_db(mass, amount);
//    sort_db(mass, amount);
//    print_db(mass, amount);
//    // print_db(mass, amount);
//    write_db("data.txt", mass, amount);
//
//    return 0;
//    
//}
//
