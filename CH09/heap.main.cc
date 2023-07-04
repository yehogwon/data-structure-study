#include <iostream>
#include "heap.hh"

int main() {
    std::cout << " ========== Heap with priority ==========" << std::endl;
    PriorHeap<char> pheap;

    pheap.insert('A', 1);
    pheap.insert('B', 2);
    pheap.insert('C', 3);
    std::cout << pheap.remove() << std::endl;

    pheap.insert('A', 1);
    pheap.insert('B', 2);
    pheap.insert('C', 3);
    std::cout << pheap.remove() << std::endl;

    while (!pheap.empty()) std::cout << pheap.remove() << std::endl;

    std::cout << " ========== Heap with comparison ==========" << std::endl;
    CompHeap<char> cheap([](const char &a, const char &b) { return (a - b) > 0; });

    cheap.insert('A');
    cheap.insert('B');
    cheap.insert('C');
    std::cout << cheap.remove() << std::endl;

    cheap.insert('A');
    cheap.insert('B');
    cheap.insert('C');
    std::cout << cheap.remove() << std::endl;

    while (!cheap.empty()) std::cout << cheap.remove() << std::endl;

    return 0;
}
