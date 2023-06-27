#include <iostream>
#include "linked.double.hh"

using List = DoublyLinkedList<int>;

int main() {
    List list;
    int data;

    for (int i = 1; i <= 8; i++) list.insert(i);

    if (list.first(data)) {
        std::cout << data << " ";
        while (list.next(data)) std::cout << data << " ";
        while (list.previous(data)) std::cout << data << " ";
        std::cout << std::endl;
    }

    return 0;
}
