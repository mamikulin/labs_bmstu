#include "head.hpp"

//Слова текста из малых латинских букв записаны не менее чем через один пробел;
//   текст оканчивается точкой. БЕЗ ИСПОЛЬЗОВАНИЯ конструкции STRING:
//а) написать программу ввода такого текста с клавиатуры;
//б) напечатать все слова, отличающиеся от последнего слова, в алфавитном порядке.

void read(char* s, int& len){
    char sym;
    while (sym != '.')
    {
        sym = _getch();
        if (((sym >= 'a')&&(sym<='z')) || sym == ' '){
            s[len] = sym;
            len++;
            _putch(sym);
        }else if (sym == '\b') {
            if (len > 0) {
                s[len] = ' ';
                len--;
                _putch('\b');
                _putch(' ');
                _putch('\b');
            }
        }
    }
    s[len] = sym;
    len++;
    _putch('\n');

}

int compare(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            return -1;
        } else if (a[i] > b[i]) {
            return 1;
        }
        i++;
    }
    
    if (a[i] == '\0' && b[i] != '\0') {
        return -1;
    } else if (a[i] != '\0' && b[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

void sort(char** mass, int& lenw) {
    for (int i = 0; i < lenw; i++) {
        if (mass[i][0] != '\0'){
            for (int j = 0; j < lenw - i - 1; j++) {
                if (compare(mass[j], mass[j+1]) > 0){
                    int k = 0;
                    while (mass[j][k] != '\0'){
                        k++;
                    }
                    char* c = new char[k+1];
                    
                    c = mass[j];
                    mass[j] =  mass[j+1];
                    mass[j+1] = c;
                }
            }
        }
    }
    
}

void out(char** mass, int& lenw){
    int j;
    for(int i = 0; i < lenw; i++){
        j = 0;
        
        while(mass[i][j] != '\0'){
            _putch(mass[i][j]);
            j++;
        }
        _putch(' ');
    }
   
}

char** split(char* s, int len, int& lenw, char** mass){
    bool space_act = true;
    
    for (int i = 0; i< len; i++){
        if((s[i] != ' ') && (space_act)){
            lenw++;
        }

        if (s[i] == ' '){
            space_act = true;
        }else{
            space_act = false;
        }
    }
    mass = new char* [lenw];
    int* mass_w_len = new int[lenw];
    for(int i = 0; i<lenw; i++){
        mass_w_len[i] = 0;
    }
    space_act = false;

    int w;
    if(s[0] == ' '){w = -1;}else{w = 0;}
    for (int i = 0; i< len; i++){
        
        if((s[i] != ' ') && (space_act)){
            w++;
        }

        if (s[i] == ' '){
            space_act = true;
        }else{
            space_act = false;
        }

        

        if(!space_act){
            mass_w_len[w]++;
        }
    }

    for(int i = 0; i<lenw; i++){
        mass[i] = new char[mass_w_len[i]+1];
    }

    
    int j;
    if(s[0] == ' '){w = -1;}else{w = 0;}
    for (int i = 0; i < len; i++){
        
        if((s[i] != ' ') && (space_act)){
            w++;
            j = 0;
            
        }

        if (s[i] == ' ' ){
            space_act = true;
        
        }else{
            space_act = false;
        }

        if(!space_act){
            
            mass[w][j] = s[i];
            j++;
            mass[w][j] = '\0';
        }
    }
    
    if(s[len -  2] == ' '){
        lenw--;
    }else{
        mass[lenw-1][mass_w_len[lenw-1]-1] = '\0';
    }
    return mass;
}

bool is_same(const char* a, const char* b){
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0'){
        if (a[i] != b[i]){
            return false;
        }
        i++;
    }
    
    return true;

}

char** check(char** mass, int& lenw){
    for (int i = 0; i < lenw; i++){
    
        if(is_same(mass[i], mass[lenw-1])){
            mass[i][0] = '\0';
        }
    }
    return mass;
}

int main() {
    int l = 0, lenw = 0, j = 0;
    char* s = new char[256];
    char** mass;
    
    read(s, l);
    
    mass = split(s, l, lenw, mass);
    
    mass = check(mass, lenw);
    

    sort(mass, lenw);
    
    _putch('\n');
    out(mass, lenw);
    _putch('\n');
    for(int i = 0; i < lenw; i++){
        delete[] mass[i];
    }
    delete[] mass;
    char stop = _getch();

    return 0;
}
