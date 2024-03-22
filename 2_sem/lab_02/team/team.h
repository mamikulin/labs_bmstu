#include <iostream> 
#include <fstream>
#include <iomanip>


class Worker{
    private:
        static int total;
        int id_;

        char* name_;
        char* prof_;
        int zp_; 
        
        bool active_;
        
        void set_name(char* name){
            delete [] name_;
            name_ = new char[16];
            strcpy(name_, name);
        }
        void set_prof(char* prof){
            delete [] prof_;
            prof_ = new char[16];
            strcpy(prof_, prof);
        }
        void set_zp(int zp){
            zp_ = zp;
        }
       
        void set_active(bool active){
            active_ = active;
        }

        

    public:
        void give_id(){
            id_ = total;
            total++;
        }
        Worker() {
            name_ = new char[1];
            name_[0]='\0';
            prof_ = new char[1];
            prof_[0]='\0';
            zp_= 0;
            active_ = 0;
        }

        Worker (Worker& obj);
        Worker& operator= (Worker& obj){
            this -> set_zp(obj.zp_);
            this -> set_active(obj.active_);
            this -> set_name(obj.name_);
            this -> set_prof(obj.prof_);
            return *this;
        }
        ~Worker();
        void print();
        void set_all(char*, char*, int, bool, bool);
        char* get_name();
        char* get_prof();
        int get_zp();
        bool get_active();

        friend std::ostream& operator<<(std::ostream& out, Worker &elm);
        friend std::istream& operator>>(std::istream& in, Worker &elm);

};


void read_db(char* , Worker* , int& );
void print_db(Worker* , int& );
void write_db(char* , Worker* , int& );
void find(Worker*, int& );
void sort_db(Worker*, int& );
void createnew(Worker* , int&);
void deletewo(Worker* , int& );
void edit(Worker*, int& );
int menu();

void extend(Worker* old, int size, int newsize);