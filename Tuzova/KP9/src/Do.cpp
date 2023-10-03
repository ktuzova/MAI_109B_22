#include "../include/Do.hpp"


void Do::bubbleSort(Record table[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (table[j].key > table[j + 1].key) {
                std::swap(table[j], table[j + 1]);
            }
        }
    }
}
 
int Do::binarySearch(Record table[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
 
        if (table[mid].key == target) {
            return mid;
        } else if (table[mid].key < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}



