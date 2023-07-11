#include <iostream>
#include "interpolation.search.hh"

int main() {
    item<int, double> items[] = {
        {1, 1.1},
        {2, 2.2},
        {3, 3.3},
        {4, 4.4},
        {5, 5.5},
        {6, 6.6},
        {7, 7.7},
        {8, 8.8},
        {9, 9.9},
        {10, 10.10}
    };
    auto &item = interpolation_search(items, 8, 0, 9);
    std::cout << item.key << " " << item.value << std::endl;
    return 0;
}
