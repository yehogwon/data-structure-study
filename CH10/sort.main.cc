#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
#include "sort.basic.hh"
#include "sort.advance.hh"

struct Int : public RadixElement {
    int val;
    
    Int() : val(0) {}
    Int(int val) : val(val) {}

    int length() const override {
        int val__ = val, len = 0;
        while (val__ > 0) val__ /= 10, len++;
        return len;
    }

    int operator[](int index) const override {
        int val__ = val, len = length();
        for (int i = 0; i < len - index - 1; i++) val__ /= 10;
        return val__ % 10;
    }

    operator int() const override {
        return val;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        os << vec[i] << " ";
    return os;
}

int main() {
    std::pair<const char*, std::function<std::vector<int>(const std::vector<int>&)>> outplaces[] = {
        {"Bubble Sort", bubble_sort<int>},
        {"Selection Sort", selection_sort<int>},
        {"Insertion Sort", insertion_sort<int>},
        {"Heap Sort", heap_sort<int>},
        {"Merge Sort", merge_sort<int>},
        {"Quick Sort", quick_sort<int>}
    };

    std::pair<const char*, std::function<void(std::vector<int>&)>> inplaces[] = {
        {"Bubble Sort", bubble_sort_inplace<int>},
        {"Selection Sort", selection_sort_inplace<int>},
        {"Insertion Sort", insertion_sort_inplace<int>},
        {"Heap Sort", heap_sort_inplace<int>},
        // {"Merge Sort", merge_sort_inplace<int>},
        // {"Quick Sort", quick_sort_inplace<int>}
    };

    std::cout << " =========== out-of-place sorting algorithms =========== " << std::endl;
    std::vector<int> vec = {7, 11, 3, 15, 19, 2, 6, 4, 13, 18, 5, 20, 14, 10, 9, 12, 16, 1, 17, 8};
    for (auto &alg : outplaces) std::cout << " ::: " << std::setw(15) << alg.first << " ::: " << alg.second(vec) << std::endl;
    std::cout << std::endl;

    std::cout << " ============= in-place sorting algorithms ============= " << std::endl;
    for (auto &alg : inplaces) {
        std::vector<int> vec_ = vec;
        alg.second(vec_);
        std::cout << " ::: " << std::setw(15) << alg.first << " ::: " << vec_ << std::endl;
    }

    std::cout << " ================== radix sort ================== " << std::endl;
    std::vector<Int> vec_ = std::vector<Int>(vec.begin(), vec.end());
    std::vector<Int> vec_sorted = radix_sort(vec_);
    std::cout << " ::: " << std::setw(25) << "Radix Sort (out-of-place)" << " ::: " << vec_sorted << std::endl;
    radix_sort_inplace(vec_);
    std::cout << " ::: " << std::setw(25) << "Radix Sort (in-place)" << " ::: " << vec_ << std::endl;
    
    return 0;
}
