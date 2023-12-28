//
//  funcs.cpp
//  lab_09
//
//  Created by Mike Mikulin on 27.12.2023.
//

#include "header.hpp"

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

void sort(Dictionary dictionary[], int& count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(dictionary[j].engWord, dictionary[j+1].engWord) > 0) {
                std::swap(dictionary[j], dictionary[j+1]);
            }
        }
    }
}


int search(Dictionary arr[], int& size, const char* word) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int compareResult = compare(arr[mid].engWord, word);
        if (compareResult == 0) {
            return mid;
        }
        else if (compareResult < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}
int search(Dictionary arr[], int& size, char word[]) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int compareResult = compare(arr[mid].engWord, word);
        if (compareResult == 0) {
            return mid;
        }
        else if (compareResult < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


void add(Dictionary dictionary[], int& size) {
    if (size == 100) {
        std::cout << "Словарь заполнен, добавить новое слово нельзя." << std::endl;
        return;
    }
    char eng[l_word];
    char rus[l_word];
    
    std::cout << "Введите английское слово: ";
    std::cin >> eng;
    
    std::cout << "Введите русское слово: ";
    std::cin >> rus;
    
    dictionary[size].engWord = new char[strlen(eng) + 1];
    dictionary[size].rusWord = new char[strlen(rus) + 1];
    
    std::strcpy(dictionary[size].engWord, eng);
    std::strcpy(dictionary[size].rusWord, rus);
    size++;
}



void remove(Dictionary dictionary[], int& count) {
    if (count == 0) {
        std::cout << "Словарь пуст." << std::endl;
        return;
    }
    
    char eng[50];
    
    std::cout << "Введите английское слово для удаления: ";
    std::cin >> eng;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(dictionary[i].engWord, eng) == 0) {
            delete[] dictionary[i].engWord;
            delete[] dictionary[i].rusWord;
            
            dictionary[i] = dictionary[count - 1];
            
            dictionary[count - 1].engWord = nullptr;
            dictionary[count - 1].rusWord = nullptr;
            
            count--;
            
            std::cout << "Запись удалена." << std::endl;
            return;
        }
    }
    
    std::cout << "Запись не найдена." << std::endl;
}



void save(Dictionary dictionary[], int& size) {
    std::ofstream file("dictionary.txt");
    sort(dictionary, size);

    for (int i = 0; i < size; i++) {
        file << dictionary[i].engWord << " " << dictionary[i].rusWord << std::endl;
    }

    file.close();
    std::cout << "Словарь сохранен в файл." << std::endl;
}

void print(Dictionary dictionary[], int& size) {
    if (size <= 0) {
        std::cout << "Словарь пуст." << std::endl;
        return;
    }

    std::cout << "Содержимое словаря:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << " " << dictionary[i].engWord << " " << dictionary[i].rusWord << std::endl;
    }
}

void eng_to_rus(Dictionary dictionary[], int& size) {
    if (size <= 0) {
        std::cout << "Словарь пуст." << std::endl;
        return;
    }
    char word[l_word];
    std::cout << "Введите английское слово для перевода на русский: ";
    std::cin >> word;

    int index = search(dictionary, size, word);
    if (index == -1){
        std::cout << "Слово не найдено в словаре." << std::endl;
        return;
    }
    std::cout << "Перевод слова " << word << ": " << dictionary[index].rusWord << std::endl;

}

void rus_to_eng(Dictionary dictionary[], int& size) {
    if (size <= 0) {
        std::cout << "Словарь пуст." << std::endl;
        return;
    }

    char word[l_word];
        std::cout << "Введите русское слово для перевода на английский: ";
        std::cin >> word;


    bool exist = false;
    for (int i = 0; i < size; i++) {
        if (compare(dictionary[i].rusWord, word) == 0) {
            std::cout << "Перевод слова " << word << ": " << dictionary[i].engWord << std::endl;
            exist = true;
            break;
        }
    }
    if (exist==false){
        std::cout << "Слово не найдено в словаре." << std::endl;
    }

}
void read(Dictionary dictionary[], int& size) {
    std::ifstream file("dictionary.txt");

    if (!file) {
        std::cout << "Ошибка при открытии файла." << std::endl;
        return;
    }

    char eng[l_word];
    char rus[l_word];

    while (file >> eng >> rus) {
        dictionary[size].engWord = new char[strlen(eng) + 1];
        dictionary[size].rusWord = new char[strlen(rus) + 1];

        std::strcpy(dictionary[size].engWord, eng);
        std::strcpy(dictionary[size].rusWord, rus);

        size++;
    }

    file.close();
}
