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
    std::vector<int> vec = {5, 3, 2, 4, 1};
    std::cout << " ::: Bubble Sort ::: " << bubble_sort(vec) << std::endl;
    std::cout << " ::: Selection Sort ::: " << selection_sort(vec) << std::endl;
    std::cout << " ::: Insertion Sort ::: " << insertion_sort(vec) << std::endl;
    std::cout << " ::: Heap Sort ::: " << heap_sort(vec) << std::endl;
    
    return 0;
}
