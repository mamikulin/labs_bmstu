#include "team.h"

int::Worker::total = 0;
// Planet::Planet::Planet(char* name, int d, int satellite, bool life, bool constructor){
//     set_all(name, d, satellite, life, constructor);
// }
void::Worker::set_all(char* name, char* prof, int zp, bool active, bool constructor){
    set_name(name);
    set_prof(prof);
    set_zp(zp);
    set_active(active);
    if(!constructor){
        give_id();
     }
}
void::Worker::print(){
    std::cout << std::setw(4) <<  id_ <<std::setw(16) << name_ << std::setw(12) << prof_ << std::setw(8) << zp_ << std::setw(12) << active_ << '\n';
}
Worker::Worker::~Worker(){
    delete[] name_;
    delete[] prof_; 
}
char*::Worker::get_name(){
    return name_; 
}
char*::Worker::get_prof(){
    return prof_; 
}
int::Worker::get_zp(){
    return zp_; 
}

bool::Worker::get_active(){
    return active_; 
}
Worker::Worker(Worker& obj){
    set_all(obj.name_, obj.prof_, obj.zp_, obj.active_, 0);
}

std::istream& operator>>(std::istream& in, Worker &elm){
    char name[16];
    char prof[16];
    int zp, active_i;
    bool active;

    in >> name >> prof >> zp >> active_i;
    if (active_i == 0){
        active = false;
    }else{
        active = true;
    }
    elm.set_name(name); 
    elm.set_prof(prof);
    elm.set_zp(zp);
    elm.set_active(active);

    return in;
}
void read_db(char* db_name, Worker* mass, int& amount){
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

void print_db(Worker* mass, int& amount){
    std::cout << '\n' << std::setw(4) <<  "id" << std::setw(24) << "Имя" << std::setw(20) << "Профессия" << std::setw(12) << "зп" << std::setw(20) << "активность" << '\n'<< '\n';
    
    for (int i = 0; i < amount; i++){
        mass[i].print();
    }
}

std::ostream& operator<<(std::ostream& out, Worker &elm){
    out << elm.get_name() << ' ' << elm.get_prof() << ' ' << elm.get_zp() << ' ' << elm.get_active() << '\n';
    return out;
}
void write_db(char* db_name, Worker* mass, int& amount){
    
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

void find(Worker* mass, int& amount){
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

bool operator==(Worker &a,Worker &b) {
    return a.get_zp() == b.get_zp();
}
bool operator>(Worker &a,Worker &b) {
    return a.get_zp() < b.get_zp();
}

void sort_db(Worker* mass, int& amount){
    Worker buff;
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

void createnew(Worker* mass, int& amount){
    char name[16], prof[16];
    int zp;
    bool active;
    do{
        
        std::cout << "имя: ";
        std::cin >> name; 
        if (strcmp(name, "deleted") == 0){
            std::cout << "рабоичй не может иметь имя: 'deleted' \n";
        }
        
    }while (strcmp(name, "deleted") == 0);

    std::cout << "профессия: ";
    std::cin >> prof; 
    std::cout << "зп: ";
    std::cin >> zp;
    std::cout << "активность (1/0): ";
    std::cin >> active;
    mass[amount].set_all(name, prof, zp, active, 0);
    amount++;
}
void deletewo(Worker* mass, int& amount){
    int id;
    std::cout << "Введите id рабочего, которую вы хотите удалить: ";
    std::cin >> id;

    mass[id].set_all("deleted", "none", -1, 0, 1);
}

void edit(Worker* mass, int& amount){

    char name[16], prof[16];
    int zp, active_i, id;
    bool active;
    

    std::cout << "Введите id планеты, которую вы хотите отредактировать: ";
    std::cin >> id;
    
    do{
        
        std::cout << "Новое имя или '-1', если хотите оставить старое: ";
        std::cin >> name; 
        if (strcmp(name, "-1") == 0){
            strcpy(name, mass[id].get_name()); 
        }else if (strcmp(name, "deleted") == 0){
            std::cout << "рабочий не может иметь имя: 'deleted' \n";
        }
        
    }while (strcmp(name, "deleted") == 0);
    std::cout << "Новую профессию или '-1', если хотите оставить старую: ";
    std::cin >> prof; 
    if (strcmp(prof, "-1") == 0){
        strcpy(prof, mass[id].get_prof()); 
    }
    std::cout << "зп или '-1', если хотите оставить старой: ";
    std::cin >> zp;
    if (zp == -1){
        zp = mass[id].get_zp();
    }
    
   
    std::cout << "активнрость (1/0) или '-1', если хотите оставить старое состояние: ";
    std::cin >> active;
    if (active == -1){
        active = mass[id].get_active();
    }else if (active_i == '1'){
        active = true;
    }else{
        active = false;
    }
    mass[id].set_all(name, prof, zp, active, 0);
}

int menu(){
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


void extend(Worker* old, int size, int newsize){
    Worker* newarr = new Worker[newsize];
    for (int i = 0; i < size; i++){
        newarr[i] = old[i];
    }
    old = newarr;
    
}