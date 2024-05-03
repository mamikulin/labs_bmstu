
#include "product/product.h"

Product** Product::products = new Product*[2];

int Product::max_size = 2;
int Product::size = 0;
int Product::r = 1;

int main() {
    if(Product::r == -1){
        Knot a("somebody1", "Силумин", 23, 2), b("somebody2", "mat", 89, 4), l("somebody3", "tam", 89, 4);
        Mechanism c("some1", "OOP", 78, 6, 78);
        Detail d("кто-то", "OOP2", 247, 28, "teacher"), e("кто-то(2)", "class", 20, 4, "teacher1");
        
        Product* a_ptr = &a; 
        a_ptr -> add();
        
        a.add();
        b.add();
        l.add();
        c.add();
        d.add();
        e.add();

        for(int i = 0; i < Product::size; i++){

            Product::products[i] -> show();
        }
    }else{
        Knot a("somebody1", "Силумин", 23, 2), b("somebody2", "mat", 89, 4), l("somebody3", "tam", 89, 4);
        Mechanism c("some1", "OOP", 78, 6, 78);
        Detail d("кто-то", "OOP2", 247, 28, "teacher"), e("кто-то(2)", "class", 20, 4, "teacher1");
        for(int i = 0; i < Product::size; i++){

            Product::products[i] -> show();
        }
    }

    

    delete[] Product::products;
    return 0;
}
