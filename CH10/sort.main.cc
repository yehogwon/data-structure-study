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
        int arr[4] = {3, 2, 4, 1};
        std::cout << " === Bubble Sort === " << std::endl;
        bubble_sort(arr, 4);
        print(arr, 4);
    }
    {
        int arr[4] = {3, 2, 4, 1};
        std::cout << " === Selection Sort === " << std::endl;
        selection_sort(arr, 4);
        print(arr, 4);
    }
    
    return 0;
}
