#include "header.hpp"

const int Size = 16;


int::Planet::total = 0;
Planet::Planet::Planet(char* name, int d, int satellite, bool life, bool constructor){
    set_all(name, d, satellite, life, constructor);
}
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

template <typename T>
void clear(T mass, int c){
    for (int i = 0; i < c; i++){
        delete mass[i];
    }
    
    delete[] mass;
}

std::istream& operator>>(std::istream& in, Planet elm){
    char name[16];
    int d, satellite;
    bool life;

    in >> name >> d >> life >>satellite;
    elm.set_all(name, d, satellite, life, 0);

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
    char** lines = new char*[Size];

    while(db.getline(buffer, sizeof(buffer), '\n')){
        lines[c] = new char[128];
        strcpy(lines[c], buffer);
        c++;
    }
    db.clear();
    db.seekg(0);


    db.close();

    int j, js = 0;

    char** names = new char*[16]; 
    char** ds = new char*[16]; 
    char** satellites = new char*[16];
    bool* lives = new bool[16];
    int k = 0;
    for(int i = 0; i < c; i++){
        j = 0, k = 0;

        names[i] = new char[16];
        ds[i] = new char[4];
        satellites[i] = new char[4];
        js=0;
        while(lines[i][j] != '\0'){
            
            if (lines[i][j] == ' '){
            
                k++;
                js=0;
            }else{
                if (k == 0){   
                    names[i][js] = lines[i][j];
                }else if (k == 1){   
                    ds[i][js] = lines[i][j];
                }else if (k == 3){   
                    satellites[i][js] = lines[i][j];
                }else{
                    if (lines[i][j] == '1'){
                        lives[i] = true;
                    }else{
                        lives[i] = false;
                    }
                    
                }

                js++;
            }
            j++;
        }
    }
    
    for(int i = 0; i < c; i++){
        mass[i].set_all(names[i], atoi(ds[i]),  atoi(satellites[i]), lives[i], false);
        // std::cout << names[i] << " " << atoi(ds[i])  << " " << atoi(satellites[i]) << " " << lives[i] << '\n';
    }
    amount = c;
    // clear(lines, c);
    // clear(names, c);
    // clear(ds, c);
    // clear(satellites, c);
    delete[] lives;
}
void print_db(Planet* mass, int& amount){
    std::cout << '\n' << std::setw(4) <<  "id" << std::setw(24) << "Название" << std::setw(20) << "Диаметр" << std::setw(12) << "Жизнь" << std::setw(20) << "Спутники" << '\n'<< '\n';
    
    for (int i = 0; i < amount; i++){
        mass[i].print();
    }
}

std::ostream& operator<<(std::ostream& out, Planet elm){
    out << elm.get_name() << ' ' << elm.get_d() << ' ' << elm.get_life() << ' ' << elm.get_satellite() << '\n';
    return out;
}
void write_db(char* db_name, Planet* mass, int& amount){
    
    std::ofstream db(db_name, std::ofstream::trunc);
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
void sort_db(Planet* mass, int& amount){
    for(int i = 0; i < amount - 1; i++){
        for(int j = 0; j < amount - i - 1; j++){
            if (std::strcmp(mass[j].get_name(), mass[j+1].get_name()) > 0){
                std::cout << j << " " << j + 1 << '\n';
                // std::swap(mass[j], mass[j+1]);
            }
        }
    }
}

void createnew(Planet* mass, int& amount){
    std::cout << amount << '\n';
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


int main(){
    int c = 0, k;
    Planet* mass = new Planet[Size];
    int& amount = c;
    read_db("data.txt", mass, amount);
    // print_db(mass, amount);
    // createnew(mass, amount);
    // print_db(mass, amount);
    // deletepl(mass, amount);
    // print_db(mass, amount);
    // edit(mass, amount);
    print_db(mass, amount);
    // find(mass, amount);
    // print_db(mass, amount);
    sort_db(mass, amount);
    print_db(mass, amount);
    // print_db(mass, amount);
    write_db("data.txt", mass, amount);

    return 0; 
    
}



