#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "myvector.h"


template<class INF>
class MySet : public MyVector<INF> {
 public:
  MySet(INF el = NULL) : MyVector<INF>(el){};
  bool operator==(MySet &s){   //done
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
  MySet &operator+=(MySet &s){
    
    MySet s_n = *this + s;
    *this = s_n; 
    return *this;
  }
  MySet &operator-=(MySet &s){
    MySet s_n = *this - s;
    *this = s_n; 
    return *this;
  } 
  MySet &operator*=(MySet &s){
    MySet s_n = *this * s;
    *this = s_n; 
    return *this;
  } 
  void add_Element(INF el);    
  void delete_Element(INF el); 
  bool is_element(INF el);     
  // friend std::ostream &operator<<(std::ostream &out, MySet &s);
  friend MySet operator+(MySet &s1, MySet &s2){
    MySet s = s1;
    for(int i = 0; i < s2.get_size(); i++){
      s.add_Element(s2[i]);
      
    }
    return s; 
  }
  friend MySet operator-(MySet &s1, MySet &s2){
    MySet s;

    for(int i = 0; i < s2.get_size(); i++){
      if (!s2.is_element(s1[i])){
        s.add_Element(s1[i]);
      }
    }
  
    return s;
  }
  friend MySet operator*(MySet &s1, MySet &s2){
    MySet s;

    for(int i = 0; i < s2.get_size(); i++){
      if (s1.is_element(s2[i])){
        s.add_Element(s2[i]);
      }
    }
  
    return s;
  }

  
};

#endif  // INHERITANCE_MYSET_H
