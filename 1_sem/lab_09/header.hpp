//
//  header.hpp
//  lab_09
//
//  Created by Mike Mikulin on 27.12.2023.
//

#ifndef header_hpp
#define header_hpp

#include <iostream>
#include <fstream>
#include <cstring>

#define l_word 31
struct Dictionary {
    char* engWord;
    char* rusWord;
};

int compare(const char* a, const char* b);
void sort(Dictionary arr[], int& size);
int search(Dictionary arr[], int& size, const char* word);
int search(Dictionary arr[], int& size, const char word[]);
void add(Dictionary dictionary[], int& size);
void remove(Dictionary dictionary[], int& size);
void save(Dictionary dictionary[], int& size);
void print(Dictionary dictionary[], int& size);
void eng_to_rus(Dictionary dictionary[], int& size);
void rus_to_eng(Dictionary dictionary[], int& size);
void read(Dictionary dictionary[], int& size);

#endif /* header_hpp */
