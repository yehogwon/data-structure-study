#include <iostream>
#include "priority.queue.hh"

int main() {
    PriorityQueue<char> pqueue([](const char &a, const char &b) { return a < b; });

    pqueue.enqueue('A');
    pqueue.enqueue('B');
    pqueue.enqueue('C');
    std::cout << pqueue.dequeue() << std::endl;

    pqueue.enqueue('A');
    pqueue.enqueue('B');
    pqueue.enqueue('C');
    std::cout << pqueue.dequeue() << std::endl;

    while (!pqueue.empty()) std::cout << pqueue.dequeue() << std::endl;

    return 0;
}
