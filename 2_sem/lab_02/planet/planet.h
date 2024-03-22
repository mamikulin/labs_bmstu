#include <iostream> 
#include <fstream>
#include <iomanip>


class Planet{
    private:
        static int total;
        int id_;

        char* name_;
        int d_; 
        int satellite_; 
        bool life_;
        
        void set_name(char* name){
            delete [] name_;
            name_ = new char[16];
            strcpy(name_, name);
        }
        void set_d(int d){
            d_ = d;
        }
        void set_satellite(int satellite){
            satellite_ = satellite;
        }
        void set_life(bool life){
            life_ = life;
        }

        

    public:
        void give_id(){
            id_ = total;
            total++;
        }
        Planet() {
            name_ = new char[1];
            name_[0]='\0';
            d_= 0;
            satellite_ = 0; 
            life_ = 0;
            
        }

        Planet (Planet& obj);
        Planet& operator= (Planet& obj){
            //if(name_){
              //  delete[] name_;
            //}
            this -> set_d(obj.d_);
            this -> set_satellite(obj.satellite_);
            this -> set_life(obj.life_);
            this -> set_name(obj.name_);
            
            return *this;
        }
        ~Planet();
        void print();
        void set_all(char*, int, int, bool, bool);
        char* get_name();
        int get_d();
        int get_satellite();
        bool get_life();

        friend std::ostream& operator<<(std::ostream& out, Planet &elm);
        friend std::istream& operator>>(std::istream& in, Planet &elm);

};


void read_db(char* , Planet* , int& );
void print_db(Planet* , int& );
void write_db(char* , Planet* , int& );
void find(Planet*, int& );
void sort_db(Planet*, int& );
void createnew(Planet* , int&);
void deletepl(Planet* , int& );
void edit(Planet*, int& );
int menu();