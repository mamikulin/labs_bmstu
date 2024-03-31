#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "myvector.h"


template<class INF>
class MySet : public MyVector<INF> {
 public:
  MySet(INF el = NULL) : MyVector<INF>(el){};
  bool operator==(MySet &s);
  MySet &operator+=(MySet &s);
  MySet &operator-=(MySet &s);
  MySet &operator*=(MySet &s);
  void add_element(INF el);
  void delete_element(INF el);
  bool is_element(INF el);
  friend std::ostream &operator<<(std::ostream &out, MySet &s);
  friend MySet operator+(MySet &s1, MySet &s2);
  friend MySet operator-(MySet &s1, MySet &s2);
  friend MySet operator*(MySet &s1, MySet &s2);
};

#endif  // INHERITANCE_MYSET_H
