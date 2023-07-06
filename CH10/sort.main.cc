#include <iostream>
#include "sort.basic.hh"

template <typename T>
void print(T *arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    {
        int arr[5] = {5, 3, 2, 4, 1};
        std::cout << " === Bubble Sort === " << std::endl;
        bubble_sort(arr, 5);
        print(arr, 5);
    }
    {
        int arr[5] = {5, 3, 2, 4, 1};
        std::cout << " === Selection Sort === " << std::endl;
        selection_sort(arr, 5);
        print(arr, 5);
    }
    {
        int arr[5] = {5, 3, 2, 4, 1};
        std::cout << " === Insertion Sort === " << std::endl;
        insertion_sort(arr, 5);
        print(arr, 5);
    }
    
    return 0;
}
