//
//  header.hpp
//  lab_02_x
//
//  Created by Mike Mikulin on 22.02.2024.
//

#ifndef header_hpp
#define header_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

class Planet{
    private:

        

        char* name_;
        int d_;
        int satellite_;
        bool life_;

        void set_name(char* name){
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
        Planet(char* name = "unknown", int d = -1, int satellite = -1, bool life = false){
            name_ = new char[16];
           
            strcpy(name_, name);
            d_ = d;
            satellite_ = satellite;
            life_ = life;
        }
        ~Planet(){
            delete[] name_;
        }

        void print(){
            std::cout << " "<< name_ << " " << d_ << " " << life_<< " " << satellite_ << '\n';
        }

        void set_all(char* name, int d, int satellite, bool life){
            
            set_name(name);
            set_d(d);
            set_satellite(satellite);
            set_life(life);
        }

};

void read_db(char*);


#endif /* header_hpp */
