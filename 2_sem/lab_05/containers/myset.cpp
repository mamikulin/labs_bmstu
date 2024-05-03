    #include "myset.h"



    template <class INF>
    bool MySet<INF>::is_element(INF el){
        
        if(this -> find(el) == -1){
            return false;
        }
        return true;
        
    }


    template <class INF>
    void MySet<INF>::add_element(INF el){
        
        if(!this -> is_element(el)){
            
            this -> MyVector::add_element(el);
        }
        
    }

    template <class INF>
    void MySet<INF>::delete_element(INF el){
        if(this->is_element(el)){
            this -> MyVector::delete_element(this -> find(el));
        }
    }

