#include <iostream>
#include "linked.double.hh"

using List = DoublyLinkedList<int>;
using DummyList = DummyDoublyLinkedList<int>;

int main() {
    int data;

    std::cout << " :::: Doubly Linked List without Dummy Nodes ::::" << std::endl;
    {
        List list;
        for (int i = 1; i <= 8; i++) list.insert(i);

        if (list.first(data)) {
            std::cout << data << " ";
            while (list.next(data)) std::cout << data << " ";
            while (list.previous(data)) std::cout << data << " ";
            std::cout << std::endl;
        }
    }
    
    std::cout << " :::: Doubly Linked List with Dummy Nodes ::::" << std::endl;
    {
        DummyList list;
        for (int i = 1; i <= 8; i++) list.insert(i);

        if (list.first(data)) {
            std::cout << data << " ";
            while (list.next(data)) std::cout << data << " ";
            std::cout << std::endl;
        }

        if (list.first(data)) {
            if (data % 2 == 0) list.remove();
            while (list.next(data)) if (data % 2 == 0) list.remove();
        }

        if (list.first(data)) {
            std::cout << data << " ";
            while (list.next(data)) std::cout << data << " ";
            std::cout << std::endl;
        }
    }

    return 0;
}
