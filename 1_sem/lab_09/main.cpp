//
//  main.cpp
//  lab_09
//
//  Created by Mike Mikulin on 27.12.2023.
//

#include "header.hpp"

int main() {
    int size = 0;
    Dictionary dictionary[100];
    read(dictionary, size);
    
    int ans;
    do {
        std::cout << "Меню:" << '\n';
        std::cout << "1 - Добавить слово в словарь" << '\n';
        std::cout << "2 - Удалить слово из словаря" << '\n';
        std::cout << "3 - Сохранить словарь в файл" << '\n';
        std::cout << "4 - Просмотреть словарь" << '\n';
        std::cout << "5 - Перевести с английского на русский" << '\n';
        std::cout << "6 - Перевести с русского на английский" << '\n';
        
        std::cout << "0 - Выход" << '\n';
        std::cout << "Выберите пункт меню: ";
        std::cin >> ans;

        switch (ans) {
            case 1:
                add(dictionary, size);
                break;
            case 2:
                remove( dictionary,  size);
                break;
            case 3:
                save( dictionary,  size);
                break;
            case 4:
                print( dictionary, size);
                break;
            case 5:
                eng_to_rus( dictionary,  size);
                break;
            case 6:
                rus_to_eng( dictionary,  size);
                break;
            case 0:
                std::cout << "Завершение программы." << '\n';
                break;
            default:
                std::cout << "Неверный ввод." << '\n';
                break;
        }

        std::cout << '\n';
    } while (ans != 0);
    
    for (int i = 0; i < size; i++) {
        delete[] dictionary[i].engWord;
        delete[] dictionary[i].rusWord;
    }
    return 0;
}
