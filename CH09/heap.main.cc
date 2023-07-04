#include <iostream>
#include "heap.hh"

int main() {
    Heap<char> heap;

    heap.insert('A', 1);
    heap.insert('B', 2);
    heap.insert('C', 3);
    std::cout << heap.remove() << std::endl;

    heap.insert('A', 1);
    heap.insert('B', 2);
    heap.insert('C', 3);
    std::cout << heap.remove() << std::endl;

    while (!heap.empty())
        std::cout << heap.remove() << std::endl;

    return 0;
}
