#include <fstream>
#include <iostream>

char* readfile(char* filename);
int getlen(char* filename);
int* getclues(char* s);
char* encrypting(char* s, int* clues, int** stat);
void writetofile(char* filename, char* s);
char* decoding(char* s, int* clues);
int getwlen(char* filename);
void print_stat(int** stat);
int sum(int* mass);

int main(){
    int mode;
    char* sr;
    int** stat = new int*[256];
    for ( int i =0 ; i < 256; i++){
        stat[i] = new int[256];
    }
    
    std::cout << "зашифровать - 0; расшифровать - 1: ";
    std::cin >> mode;

    char* s =readfile("clues.txt");
    int* clues = getclues(s);
    
    if (mode == 0){
        s = readfile("tobeencrypted.txt");
        sr = encrypting(s, clues, stat);
        writetofile("encrypted.txt", sr);
        sr = readfile("encrypted.txt");
        char* ds = decoding(sr, clues);
        writetofile("decoded.txt", ds);
        print_stat(stat);
    }else if (mode == 1){
        sr = readfile("encrypted.txt");
        char* ds = decoding(sr, clues);
        writetofile("decoded.txt", ds);
    }
    
    return 0;
}

int getlen(char* filename){
    char ch;
    int len = 0;
    
    std::fstream file(filename);
    if (!file.is_open()){
        std::cout << "файл не найден" << '\n';
        exit(404);
    }
    for (file>>ch; !file.eof(); file>>std::noskipws>>ch){
        len++;
    }
    
    file.close();
    return len;
    
}

char* readfile(char* filename){
  
    char ch;
    int len = getlen(filename);
    std::fstream file(filename);
    if (!file.is_open()){
        std::cout << "файл не найден" << '\n';
        exit(404);
    }
    
    
    
    char* s = new char[len+1];
    file.clear();
    file.seekg(0);
    
    for (int i =0; i< len; i++){
        file.get(ch);
        s[i] = ch;
    }
    file.close();
    return s;
}



int* getclues(char* s){
    std::fstream file("clues.txt");
    if (!file.is_open()){
            exit(404);
    }
    int len = getlen("clues.txt");
    char ch;
//    int c = 0;
//    for (int i =0; i< len; i++){
//        file.get(ch);
//        if (isspace(ch)){
//            c++;
//        }
//    }
//    file.clear();
//    file.seekg(0);
    int* clues = new int[getwlen("clues.txt")];
    int c = 0;
    
    for (int i =0; i< len; i++){
        file.get(ch);
        clues[c] += static_cast<int>(ch);
        if (isspace(ch)){
            clues[c] -= 10;
            c++;
        }
    }
    
    file.close();
    return clues;
}

char* encrypting(char* s, int* clues, int** stat){
    int len = getlen("tobeencrypted.txt");
    
    char* sr = new char[len+1];
    
    for (int i = 0; i<len; i++ ){
//        std::cout <<256 + static_cast<int>(s[i])  << " " << 256 + ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256) << '\n';
        if ((static_cast<int>(s[i]) < 0) && ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256 < 0)){
            stat[256 + static_cast<int>(s[i])][256 + ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256)]++;
        }else if ((static_cast<int>(s[i]) < 0) && ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256 >= 0)){
            stat[256 + static_cast<int>(s[i])][((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256)]++;
        }else if ((static_cast<int>(s[i]) >= 0)&& ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256 < 0)){
            stat[static_cast<int>(s[i])][256 + ((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256)]++;
        }else{
          stat[static_cast<int>(s[i])][((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256)]++;
        }
        
        sr[i] = static_cast<char>((static_cast<int>(s[i]) + clues[i%getwlen("clues.txt")]) % 256);
    }
    
    return sr;
}

void writetofile(char* filename, char* s){
    std::ofstream file(filename);
    if (!file.is_open()){
            exit(404);
    }
    int len = std::max(getlen("tobeencrypted.txt"), getlen("encrypted.txt"));
    for(int i = 0; i < len; i++){
        file << s[i];
    }
    
    
    
    file.close();
}

char* decoding(char* s, int* clues){
    int len = getlen("encrypted.txt");
    char* sr = new char[len+1];
    
    for (int i = 0; i<len; i++ ){
        sr[i] = static_cast<char>((static_cast<int>(s[i])+256 - clues[i%getwlen("clues.txt")]) % 256);
    }
    
    return sr;
}

int getwlen(char* filename){
    std::fstream file(filename);
    if (!file.is_open()){
            exit(404);
    }
    int len = getlen(filename);
    char ch;
    int c = 0;
    for (int i =0; i< len; i++){
        file.get(ch);
        if (isspace(ch)){
            c++;
        }
    }
    
    return c;
    
    file.close();
}

void print_stat(int** stat){
    for (int i = 10; i < 256; i++ ){
        if (sum(stat[i]) != 0){
            std::cout << i << "  " ;
            for (int j= 0; j < 256; j++ ){
                if (stat[i][j] != 0){
                    std::cout<< "| " << j << " "<< stat[i][j];
                }
            }
            std::cout << '\n';
            std::cout << '\n';
        }
    }
}


int sum(int* mass){
    int r = 0;
    for (int i = 0; i < 256; i++){
        r += mass[i];
    }
    return r;
}
