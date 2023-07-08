#include <iostream>
#include <vector>
#include "sort.basic.hh"
#include "sort.advance.hh"

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        os << vec[i] << " ";
    return os;
}

int main() {
    std::vector<int> vec = {7, 11, 3, 15, 19, 2, 6, 4, 13, 18, 5, 20, 14, 10, 9, 12, 16, 1, 17, 8};
    std::cout << " ::: Bubble Sort ::: " << bubble_sort(vec) << std::endl;
    std::cout << " ::: Selection Sort ::: " << selection_sort(vec) << std::endl;
    std::cout << " ::: Insertion Sort ::: " << insertion_sort(vec) << std::endl;
    std::cout << " ::: Heap Sort ::: " << heap_sort(vec) << std::endl;
    std::cout << " ::: Merge Sort ::: " << merge_sort(vec) << std::endl;
    std::cout << " ::: Quick Sort ::: " << quick_sort(vec) << std::endl;
    
    return 0;
}
