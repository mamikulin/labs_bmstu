#include "myvector.h"

// TODO: реализация класса MyVector

template<class INF>
void MyVector<INF>::resize(){
    if (size == max_size){
        INF* pdata_n = new INF[max_size * 2];
        for (int i = 0; i < max_size; i++){
            pdata_n[i] = pdata[i] ;
        }
        pdata = pdata_n;
        
        max_size *= 2;
    }else if(size == max_size/4){
        INF* pdata_n = new INF[max_size/2];
        for (int i = 0; i < max_size/4; i++){
            pdata_n[i] = pdata[i];
        }
        pdata = pdata_n;
        max_size /= 2;
    }
}

template<class INF>
void MyVector<INF>::sort(){
    bool f;
    int len = size;
    for (int i = len; i > 0; i--){
        f = false;
        for (int j = 0; j < len - 1 - (len-i); j++){
            int old = pdata[j];
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



template<class INF>
void MyVector<INF>::add_element(INF el){
    size += 1; 
    resize();
    pdata[size-1] = el;
    sort();
}

template<class INF>
bool MyVector<INF>::delete_element(int i){
    if (i < size){
        for(i++; i < size; i++){
            pdata[i-1] = pdata[i];
        }
        size--; 
        resize();
        return true;
    }
    return false;
}

template<class INF>
INF MyVector<INF>::operator[](int i){
    return pdata[i];
}


template<class INF>
int MyVector<INF>::find(INF el){
    int top = size, bottom = 0, len = size, mid;
    
    while(top - bottom > -1){
        mid = (top + bottom) / 2;
        if (el == pdata[mid]){
            return mid;
        }else  if (len == 1){
            std::cout << "not found" << '\n';
            return -1;
        }else if(el < pdata[mid]){
            top =  mid;
        }else{
            bottom = mid;
        }
        len /= 2;  
    }

}
