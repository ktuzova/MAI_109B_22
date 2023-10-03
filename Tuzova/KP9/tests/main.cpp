#include <iostream>
#include <algorithm>
#include <ctime> 
#include <cstdlib> 

#include "../include/Do.hpp"
//#include "../src/Do.cpp"
//#include "../include/Record.hpp"

int main() {
    const int maxTableSize = 12;
    Record table[maxTableSize];
    int k = 0;
    int tableSize = 0; // Текущий размер таблицы
    std::cout << "Введите размер таблицы  от 8 до 12 эелементов";
    std::cin >> k;
    while ((k > 12) || (k < 8)){
        std::cout << "Введите размер таблицы  от 8 до 12 эелементов";
        std::cin >> k;
    }
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(0)));
 
    // Генерация случайных данных для таблицы
    for (int i = 0; i < k; i++) {
        table[tableSize].key = rand() % 100; // Генерируем случайный ключ (в данном случае, от 0 до 99)
        table[tableSize].data = rand() % 1000; // Генерируем случайные данные (в данном случае, от 0 до 999)
        tableSize++;
    }
    std::cout << "Неотсортированная таблица:" << std::endl;
    for (int i = 0; i < tableSize; i++) {
        std::cout << "Ключ: " << table[i].key << ", Данные: " << table[i].data << std::endl;
    }
    Do d1;
    d1.bubbleSort(table, tableSize);
    
    std::cout << "Отсортированаая таблица:" << std::endl;
    for (int i = 0; i < tableSize; i++) {
        std::cout << "Ключ: " << table[i].key << ", Данные: " << table[i].data << std::endl;
    }
 
    int targetKey;
    std::cout << "Введите ключ для поиска: ";
    std::cin >> targetKey;
    int index = d1.binarySearch(table, tableSize, targetKey);
    if (index != -1) {
        std::cout << "Элемент найден. Данные: " << table[index].data << std::endl;
    } else {
        std::cout << "Элемент не найден." << std::endl;
    }
 
    return 0;
}
