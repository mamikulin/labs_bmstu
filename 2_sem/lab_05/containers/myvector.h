#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>



const int MAX_SIZE = 5;

template<class INF>
class MyVector {
 protected:
  int max_size;
  int size;
  INF* pdata;
  void resize();  
  
 public:
 
  
  
  MyVector(INF el = NULL, int max_size_g = MAX_SIZE){
    max_size = max_size_g;
    pdata = new INF[MAX_SIZE];
    size = 0;
  }
  
  MyVector(MyVector &v){ 
    pdata = new INF[MAX_SIZE];
    size = 0;
    *this = v; 

  }
  ~MyVector(){  
    delete[] pdata;
  }
  void add_element(INF el);  
  bool delete_element(int i);  
  INF operator[](int i);  
  void sort();  
  int get_size() { return size; }  
  int get_max_size() { return max_size; }  
  int find(INF el);  
  void operator=(MyVector &v){  
    for (int i = this -> size; i >= 1; i--){
      this -> delete_element(0);
    }
    for(int i = 0; i < v.size; i++){  
      this -> add_element(v.pdata[i]);
    }
    
  }
  
  friend std::ostream &operator<< (std::ostream& out, MyVector<INF>& v){
    std::cout << "{";
    for (int i = 0; i < v.size; i++){
        std::cout << v.pdata[i];
        if (i != v.size - 1){
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

    return out;
}
};

#endif  // INHERITANCE_MYVECTOR_H

