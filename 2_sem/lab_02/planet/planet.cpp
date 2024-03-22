#include "planet.h"

int::Planet::total = 0;
// Planet::Planet::Planet(char* name, int d, int satellite, bool life, bool constructor){
//     set_all(name, d, satellite, life, constructor);
// }
void::Planet::set_all(char* name, int d, int satellite, bool life, bool constructor){
    set_name(name);
        set_d(d);
        set_satellite(satellite);
        set_life(life);
        if(!constructor){
            give_id();
        }
}
void::Planet::print(){
    std::cout << std::setw(4) <<  id_ <<std::setw(16) << name_ << std::setw(12) << d_ << std::setw(8) << life_<< std::setw(12) << satellite_ << '\n';
}
Planet::Planet::~Planet(){
    delete[] name_; 
}
char*::Planet::get_name(){
    return name_; 
}
int::Planet::get_d(){
    return d_; 
}
int::Planet::get_satellite(){
    return satellite_; 
}
bool::Planet::get_life(){
    return life_; 
}
Planet::Planet(Planet& obj){
    set_all(obj.name_, obj.d_, obj.satellite_, obj.life_, 0);
}

std::istream& operator>>(std::istream& in, Planet &elm){
    char name[16];
    int d, satellite, life_i;
    bool life;

    in >> name >> d >> life_i >> satellite;
    if (life_i == 0){
        life = false;
    }else{
        life = true;
    }
    elm.set_name(name); elm.set_d(d);
    elm.set_satellite(satellite), elm.set_life(life);
   //elm.set_all(name, d, satellite, life, 0);

    return in;
}
void read_db(char* db_name, Planet* mass, int& amount){
    std::fstream db(db_name);
    if (!db.is_open()){
        std::cout << "db was not found 1" << '\n';
        exit(1);
    }

    char buffer[128];
    int c = 0; 
    
    while(db.getline(buffer, sizeof(buffer), '\n')){
        c++;
    }


    db.clear();
    db.seekg(0);

    for(int i =0; i < c; i++){
        db >> mass[i];
        mass[i].give_id();
    }
    
    db.close();
    amount = c;
    
}

void print_db(Planet* mass, int& amount){
    std::cout << '\n' << std::setw(4) <<  "id" << std::setw(24) << "Название" << std::setw(20) << "Диаметр" << std::setw(12) << "Жизнь" << std::setw(20) << "Спутники" << '\n'<< '\n';
    
    for (int i = 0; i < amount; i++){
        mass[i].print();
    }
}

std::ostream& operator<<(std::ostream& out, Planet &elm){
    out << elm.get_name() << ' ' << elm.get_d() << ' ' << elm.get_life() << ' ' << elm.get_satellite() << '\n';
    return out;
}
void write_db(char* db_name, Planet* mass, int& amount){
    
    std::ofstream db(db_name, std::ios::out | std::ios::trunc);
    if (!db.is_open()){
        std::cout << "db was not found 2" << '\n';
        exit(1);
    }

    for(int i = 0; i < amount; i++)
    {   
        if (std::strcmp(mass[i].get_name(), "deleted") != 0){
            db << mass[i];
            
        }
    }


    db.close();


    }

void find(Planet* mass, int& amount){
    char* search = new char[16];
    std::cin >> search;
    for (int i = 0; i < amount; i++){
        if(strcmp(search, mass[i].get_name()) == 0){
            mass[i].print();
            return; 
        }
       
    }
    std::cout << "Такой планеты не найдено\n";
}

bool operator==(Planet &a,Planet &b) {
    return a.get_d() == b.get_d();
}
bool operator>(Planet &a,Planet &b) {
    return a.get_d() < b.get_d();
}

void sort_db(Planet* mass, int& amount){
    Planet buff;
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (mass[j] > mass[j+1]) {
                buff = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = buff;
            }
        }
    }
}

void createnew(Planet* mass, int& amount){
    char name[16];
    int d, satellite;
    bool life;
    do{
        
        std::cout << "Название: ";
        std::cin >> name; 
        if (strcmp(name, "deleted") == 0){
            std::cout << "планета не может иметь название: 'deleted' \n";
        }
        
    }while (strcmp(name, "deleted") == 0);

    std::cout << "Диаметр: ";
    std::cin >> d;
    std::cout << "Спутники: ";
    std::cin >> satellite;
    std::cout << "Жизнь (1/0): ";
    std::cin >> life;
    mass[amount].set_all(name, d, satellite, life, 0);
    amount++;
}
void deletepl(Planet* mass, int& amount){
    int id;
    std::cout << "Введите id планеты, которую вы хотите удалить: ";
    std::cin >> id;

    mass[id].set_all("deleted", -1, -1, 0, 1);
}

void edit(Planet* mass, int& amount){

    char name[16];
    int d, satellite, id, life_i;
    bool life;
    

    std::cout << "Введите id планеты, которую вы хотите отредактировать: ";
    std::cin >> id;
    
    do{
        
        std::cout << "Новое название или '-1', если хотите оставить старое: ";
        std::cin >> name; 
        if (strcmp(name, "-1") == 0){
            strcpy(name, mass[id].get_name()); 
        }else if (strcmp(name, "deleted") == 0){
            std::cout << "планета не может иметь название: 'deleted' \n";
        }
        
    }while (strcmp(name, "deleted") == 0);
    std::cout << "Диаметр или '-1', если хотите оставить старый: ";
    std::cin >> d;
    if (d == -1){
        d = mass[id].get_d();
    }
    std::cout << "Спутники или '-1', если хотите оставить старое количество: ";
    std::cin >> satellite;
    if (satellite == -1){
        satellite = mass[id].get_satellite();
    }
    std::cout << "Жизнь (1/0) или '-1', если хотите оставить старое состояние: ";
    std::cin >> life;
    if (life_i == -1){
        life = mass[id].get_life();
    }else if (life_i == '1'){
        life = true;
    }else{
        life = false;
    }
    mass[id].set_all(name, d, satellite, life, 0);
}

int menu() {
    std::cout << "===================== ГЛАВНОЕ МЕНЮ =========================\n";
    std::cout << "1 - добавить\t\t\t 4 - сортировка\n";
    std::cout << "2 - корректировка сведений\t 5 - сохранение базы в файл\n";
    std::cout << "3 - удаление\t\t\t 6 - вывод базы на экран\n";
    std::cout << "\t\t\t\t 7 - выход\n";
    int n;
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    return n;
}


