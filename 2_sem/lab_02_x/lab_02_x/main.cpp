#include "header.hpp"





int main(){
    Planet* mass = new Planet[16];
    mass[0].print();
    mass[0].set_all("Saturn", 120000, 0, 17);
    mass[0].print();
    
    read_db("data.txt");
    
    return 0;
}



