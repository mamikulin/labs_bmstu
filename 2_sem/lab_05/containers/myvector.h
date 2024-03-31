#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>



const int MAX_SIZE = 4;



template<class INF>
class MyVector {
 protected:
  int max_size;
  int size;
  INF* pdata;
  void resize(); //done
  
 public:
 
  
  
  MyVector(INF el = NULL, int max_size_g = MAX_SIZE){
    max_size = max_size_g;
    pdata = new INF[MAX_SIZE];
    size = 0;
  }
  
  MyVector(MyVector &v){//done
    pdata = new INF[MAX_SIZE];
    size = 0;
    *this = v; 

  }
  ~MyVector(){ //done
    delete[] pdata;
  }
  void add_element(INF el); //done
  bool delete_element(int i); //done
  INF operator[](int i); //done
  void sort(); //done
  int get_size() { return size; } //done
  int get_max_size() { return max_size; } //done
  int find(INF el); //done
  MyVector &operator=(MyVector &v){ //done
    for(int i = 0; i < v.size; i++){  
      add_element(v.pdata[i]);
    }
    return v; 
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

