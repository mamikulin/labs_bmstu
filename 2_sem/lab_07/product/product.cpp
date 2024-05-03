#include "product.h"

Product& Product::operator=(const Product& a){
    return *this;
}
Knot::Knot(const Knot& a){
    *this = a;
}

Knot::Knot(char* developer, char* material, int weight, int iznos){
    this -> developer = new char[strlen(developer) + 1];
    this -> material = new char[strlen(material) + 1];
    strcpy(this -> developer, developer);
    strcpy(this -> material, material);

    this -> weight = weight;
    this -> iznos = iznos;

    if (r != -1){
        
        this -> add();
    }
}

Knot&  Knot::operator=(const Knot& a){
    delete[] this -> developer;
    this -> developer = new char[strlen(a.developer) + 1];
    delete[] this -> material;
    this -> developer = new char[strlen(a.material) + 1];
    strcpy(this->developer, a.developer);
    strcpy(this->material, a.material);
    this -> weight = a.weight; 
    this -> iznos = a.iznos;

    return *this; 
}

void Product::add(){
    
    if(size == max_size){
        Product** products_n = new Product*[max_size*2];
        max_size *= 2; 
        for(int i = 0; i < size; i++){
            products_n[i] = products[i];
            
        }
        products = products_n; 
    }
    products[size] = this; 
    size++; 
}

void Knot::show(){
    std::cout << "Узел" << " Разработал: " <<  developer << "; Материал: " <<  material << "; Вес: " << weight << "; Износ: " << iznos << "%" << '\n';
}

Mechanism::Mechanism(char* developer, char* material, int weight, int iznos, int complexity) : Knot(developer,material, weight, iznos ){
    this -> complexity = complexity;
}

Mechanism& Mechanism::operator=(const Mechanism& a){
    Knot(a.developer,a.material,a.weight,a.iznos);
    this -> complexity = a.complexity;
    return *this;
 }

Mechanism::Mechanism(const Mechanism& a) : Knot(a.developer,a.material, a.weight, a.iznos){
    *this = a;
}

void Mechanism::show(){
    std::cout << "Механизм" << " Разработал: " <<  developer << "; Материал: " <<  material << "; Вес: " 
        << weight << "; Износ: " << iznos << "%" << "; сложность: "<< complexity << "%" << '\n';
}

Detail::Detail(char* developer, char* material, int weight, int iznos, char* proveril) : Knot(developer,material, weight, iznos ){
    this -> proveril = new char[strlen(proveril) + 1];
    strcpy(this -> proveril,proveril);
}

void Detail::show(){
    std::cout << "Деталь" << " Разработал: " <<  developer << "; Материал: " <<  material << "; Вес: " 
        << weight << "; Износ: " << iznos << "%" << "; Проверил: "<< proveril  << '\n';
}

Detail::~Detail(){
    delete[] proveril;
}

Detail& Detail::operator=(const Detail& a){
    Knot(a.developer,a.material,a.weight,a.iznos );
    delete[] this -> proveril;
    this -> proveril = new char[strlen(a.proveril) + 1];
    strcpy(this -> proveril,a.proveril);
    return *this;
 }

Detail::Detail(const Detail& a) : Knot(a.developer,a.material, a.weight, a.iznos){
    *this = a;
}