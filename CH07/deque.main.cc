#include <iostream>
#include "deque.hh"

int main() {
    Deque<int> dq;

    dq.add_front(3);
    dq.add_front(2);
    dq.add_front(1);

    dq.add_rear(4);
    dq.add_rear(5);
    dq.add_rear(6);

    while (!dq.empty()) std::cout << dq.remove_front() << " ";
    std::cout << std::endl;

    dq.add_front(3);
    dq.add_front(2);
    dq.add_front(1);

    dq.add_rear(4);
    dq.add_rear(5);
    dq.add_rear(6);

    while (!dq.empty()) std::cout << dq.remove_rear() << " ";
    std::cout << std::endl;

    return 0;
}
