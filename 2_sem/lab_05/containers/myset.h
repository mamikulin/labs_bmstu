#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "myvector.h"


template<class INF>
class MySet : public Vector::MyVector<INF> {
 public:
  MySet() : Vector::MyVector<INF>(){};
  MySet(INF el) : Vector::MyVector<INF>(el){};
  bool operator==(const MySet &s){   //done
    if (this -> size == s.size){
        for(int i = 0; i < this->size; i++){
            if (this->pdata[i] != s.pdata[i]){
              return false;
            }
        }
        return true;
    }
    return false;
  }  
  MySet(const MySet &s){ 

    this -> pdata = new INF[s.size];
    this -> size = 0;
    for(int i = 0; i < s.get_size(); i++){
      this -> add_element(s.pdata[i]);
    }
  }

  MySet &operator=(const MySet s){
    int si = this -> size;
    for (int i = 0; i < si ; i++){
      this -> MyVector::delete_element(0);
    }
    for(int i = 0; i < s.size; i++){  
      this -> add_element(s.pdata[i]);
    }
    return *this; 
  }

  MySet &operator+=(const MySet &s){
    MySet s_n = *this + s;
    *this = s_n; 
    return *this;
  }
  
  MySet &operator-=(const MySet &s){
    MySet s_n = *this - s;
    *this = s_n; 
    return *this;
  } 
  MySet &operator*=(const MySet &s){
    MySet s_n = *this * s;
    *this = s_n; 
    return *this;
  } 
  void add_element(INF el);    
  void delete_element(INF el); 
  bool is_element(INF el);    
  friend MySet operator+(const MySet &s1, const MySet &s2){
    MySet s = s1;
    for(int i = 0; i < s2.get_size(); i++){
      s.add_element(s2[i]);
      
    }
    return s; 
  }
  friend MySet operator-(MySet &s1, MySet &s2){
    MySet s;

    for(int i = 0; i < s1.get_size(); i++){
      if (!s2.is_element(s1[i])){
        
        s.add_element(s1[i]);
      }
    }
    return s;
  }
  friend MySet operator*(MySet &s1, MySet &s2){
    MySet s;
    
    for(int i = 0; i < s2.get_size(); i++){
      if (s1.is_element(s2[i])){
        
        s.add_element(s2[i]);
      }
    }
  
    return s;
  }
};

template<>
bool MySet<char*>::operator==(const MySet &s){   //done

    if (this -> size == s.size){
        for(int i = 0; i < this->size; i++){
            if (strcmp(this->pdata[i], s.pdata[i]) != 0){
              return false;
            }
        }
        return true;
    }
    return false;
}  

#endif  // INHERITANCE_MYSET_H
