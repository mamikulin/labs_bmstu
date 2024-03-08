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

        void give_id(){
            id_ = total;
            total++;
        }


    public:
        Planet(char* name = "unknown", int d = -1, int satellite = -1, bool life = false, bool constructor = true);
        ~Planet();
        void print();
        void set_all(char*, int, int, bool, bool);
        char* get_name();
        int get_d();
        int get_satellite();
        bool get_life();
};

