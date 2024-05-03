#pragma once

#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H


#include <iostream>
#include <cstring>




const int MAX_SIZE = 1;

namespace Vector{

template<class INF>
class MyVector {
 protected:
  int max_size;
  int size;
  INF* pdata;
  void resize(){
    if (size == max_size){
        INF* pdata_n = new INF[max_size * 2];
        for (int i = 0; i < max_size; i++){
            pdata_n[i] = pdata[i] ;
        }
        pdata = pdata_n;
        
        max_size *= 2;
    }
    else if(size == max_size/4){
        INF* pdata_n = new INF[max_size/2];
        for (int i = 0; i < max_size/4; i++){
            // std::cout <<  pdata[i] << '\n';
            pdata_n[i] = pdata[i];
        }
        pdata = pdata_n;
        max_size /= 2;
    }
  }
  
 public:
    MyVector(int max_size_g = MAX_SIZE){
       max_size = max_size_g;
       pdata = new INF[MAX_SIZE];
       size = 0;   
    }
  MyVector(INF el , int max_size_g = MAX_SIZE){
    
    max_size = max_size_g;
    pdata = new INF[MAX_SIZE];
    size = 0;

    
    this -> add_element(el);
    
  }
  
  MyVector(const MyVector &v){ 
    pdata = new INF[v.size];
    size = 0;
    for(int i = 0; i < v.get_size(); i++){
      this -> add_element(v.pdata[i]);
    }
  }

  ~MyVector(){  
    delete[] pdata;
  }

  void add_element(const INF el){
    
    size += 1; 
    resize();
    pdata[size-1] = el;
    sort();
  }

  bool delete_element(int i){
    if (i < size){
        for(int j = i + 1; j < size; j++){
            pdata[j - 1] = pdata[j];
        }
        size--; 
        resize();
        return true;
    }
    return false;
  } 

  INF& operator[](int i) const{
    return pdata[i];
  }

  void sort(){
    bool f;
    int len = size;
    for (int i = len; i > 0; i--){
        f = false;
        for (int j = 0; j < len - (1 + (len-i)); j++){
            INF old = pdata[j];
            
            if (pdata[j] > pdata[j+1]){
                pdata[j] = pdata[j+1];
                pdata[j+1] = old;
               
                f = true;
            }
            
        }
        if (f == false){
            break;
        }
    }
  }

  int get_size() const { return size; }  

  int get_max_size() { return max_size; }  

  int find(const INF el){
    int top = size, bottom = 0, len = size, mid, test;
    
    while(top - bottom > -1){
        mid = (top + bottom) / 2;
        if (el == pdata[mid]){
            return mid;
        }else  if (len <= 1){
            return -1;
        }else if(el < pdata[mid]){
            top =  mid;
        }else{
            bottom = mid;
        }
        len /= 2;  
    }
  } 

  void operator=(const MyVector &v){  
    
    for (int i = this -> size; i >= 1; i--){
      this -> delete_element(0);
      
    }
    for(int i = 0; i < v.size; i++){  
      this -> add_element(v.pdata[i]);
    }
    
  }
  
  friend std::ostream &operator<< (std::ostream& out,const MyVector& v){
    std::cout << "{";
    for (int i = 0; i < v.size; i++){
        std::cout << v.pdata[i];
        if (i != v.size - 1){
            std::cout << ", ";
        }
    }
    std::cout << "}";

    return out;
}
};









template<>
int MyVector<char*>::find(char* el){
   
    int top = size, bottom = 0, len = size, mid, test;
  
    while(top - bottom > -1){
        // std::cout << bottom << " " << top << '\n';
        mid = (top + bottom) / 2;
        if (len < 1){
            return -1;
            
        }else if (strcmp(el, pdata[mid]) == 0){
            return mid;

            
        }else if(strcmp(el, pdata[mid]) < 0){
            top =  mid;
        }else{
            bottom = mid;
        }
        len /= 2;  
    }
}

template<>
bool MyVector<char*>::delete_element(int i){
    if (i < size){
        delete[] pdata[i];
        for(int j = i + 1; j < size; j++){
            pdata[j - 1]=pdata[j];
        }
        
        size--; 
        
        resize();
        return true;
    }
    return false;
}

template<>
void MyVector<char*>::sort(){
    bool f;
    int len = size;
    char* old = new char[16];
    for (int i = len; i > 0; i--){
        f = false;
        for (int j = 0; j < len - (1 + (len-i)); j++){
            strcpy(old, pdata[j]);
            
            if (strcmp(pdata[j], pdata[j+1]) > 0){
                strcpy(pdata[j], pdata[j+1]);
                strcpy(pdata[j+1],old);
                
               
                f = true;
            }
            
        }
        if (f == false){
            break;
        }
    }
    delete[] old;
}

template<>
void MyVector<char*>::add_element(char* el){
    
    size += 1; 
    
    resize();
    pdata[size-1] = new char[strlen(el)+1];
    strcpy(pdata[size-1], el);
    sort();
}

template<>
MyVector<char*>::~MyVector(){  
    for(int i = 0; i < this->size; i++){
        delete[] this -> pdata[i];
    }
    delete[] pdata;
}
}


  

#endif  // INHERITANCE_MYVECTOR_H

