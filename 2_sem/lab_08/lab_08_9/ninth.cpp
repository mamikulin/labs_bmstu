#include "header.h"

// #10
// Дано отображение с данными о количестве учащихся в разных классах школы:

// {'1а': 21, '1б':20, '2':25, '3а': 20, '3б': 23, '4а':25, '4б':25, '5а': 26, '5б':25, '6a':19, '6б': 18, '7а':26, '7б':25, '8':25, '9':17, '10': 15, '11’: 14}


// В программе пользователь вводит год обучения школьников, а консоль выводится количество учащихся заданного года обучения, например:

// Год обучения: 1
// Количество: 41

// Распечатать содержимое отображения в консоли, используя функцию.

template <class T, class T1> 
void make_map(std::map<T, T1>& m, std::string str){
    std::string a , b, e;
    std::vector<int> n; 
    bool pre = false; 
    int  c = 0; 
    for(int i = 0; i < str.length(); i++){
        
        if (str[i] == ' ' || str[i] == ':' || str[i] == '{' || str[i] == '}'  || str[i] == ',' || str[i] == 39){
            if(pre == true){
                n.push_back(i);
                c++;
            }
            pre = false;
            
        }else if(pre == false){
            n.push_back(i);
            
            pre = true;
    
            // std::cout << str[i];
        }
    }
    for(int i = 0; i < c*2; i+=4){
        for(int j = n[i]; j < n[i+1]; j++){
            if (int(str[j]) - 48 >= 0){
                a += str[j];
            }
        }
        for(int j = n[i+2]; j < n[i+3]; j++){
            b += str[j];
        }
        // std::cout << b << '\n';
        m[a] += std::stoi(b);
        a = e;
        b = e;
        
    }   
    
}

template <class T, class T1> 
void searc_by_year(std::map<T, T1>& m){
    T year; 
    std::cout << "Год обучения: ";
    std::cin >> year;

    std::cout <<"Количество:"<<  m[year] << '\n';
}


void ninth_b(){
    std::map<std::string, int> m;
    std::string str = "{'1а': 21, '1б':20, '2':25, '3а': 20, '3б': 23, '4а':25, '4б':25, '5а': 26, '5б':25, '6а':19, '6б': 18, '7а':26, '7б':25, '8':25, '9':17, '10': 15, '11': 14}";
    make_map(m, str);
    searc_by_year(m);
    searc_by_year(m);
    searc_by_year(m);

}

int main(){
    ninth_b();
    return 0; 
}