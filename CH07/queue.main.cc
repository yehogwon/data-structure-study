#include <iostream>
#include "queue.hh"

int main() {
    std::cout << " ==== Array-based Queue ==== " << std::endl;
    ArrayQueue<int> a_queue;
    for (int i = 1; i <= 5; i++) a_queue.enqueue(i);
    while (!a_queue.empty()) std::cout << a_queue.dequeue() << " ";
    std::cout << std::endl;

    std::cout << " ==== Linked-list-based Queue ==== " << std::endl;
    LinkedListQueue<int> l_queue;
    for (int i = 1; i <= 5; i++) l_queue.enqueue(i);
    while (!l_queue.empty()) std::cout << l_queue.dequeue() << " ";
    std::cout << std::endl;

    return 0;
}
