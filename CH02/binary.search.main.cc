#include <iostream>
#include "binary.search.hh"

int main() {
    int n, target, arr[100];
    
    std::cout << "The number of elements (less than 100)? ";
    std::cin >> n;
    
    std::cout << "Input the elements in a row: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    
    std::cout << "The target number? ";
    std::cin >> target;
    std::cout << "The index of the target number is (-1 if does not exist) -----> " << binary_search(arr, target, 0, n - 1) << std::endl;
    return 0;
}
