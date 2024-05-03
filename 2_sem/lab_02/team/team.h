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
        
        void set_name(char*);
        void set_prof(char*);
        void set_zp(int);
        void set_id(int);
       
        void set_active(bool);

        

    public:
       
        void give_id();
        Worker();
        Worker (Worker& obj);
        Worker& operator=(Worker& obj);
        ~Worker();
        void print();
        void set_all(char*, char*, int, bool, bool);
        char* get_name();
        char* get_prof();
        int get_zp();
        int get_id();
        bool get_active();

        friend std::ostream& operator<<(std::ostream& out, Worker &elm);
        friend std::istream& operator>>(std::istream& in, Worker &elm);

};

void extend(Worker* old, int size, int newsize);
void read_db(char* , Worker* , int& , int&);
void print_db(Worker* , int& );
void write_db(char* , Worker* , int& );
void find(Worker*, int& );
void sort_db(Worker*, int& );
void createnew(Worker* , int&);
void deletewo(Worker* , int& );
void edit(Worker*, int& );
int menu();

