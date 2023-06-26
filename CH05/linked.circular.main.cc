#include <iostream>
#include "linked.circular.hh"

using List = CircularLinkedList<int>;

int main() {
    int data;
    List list;
    
    list.insert_rear(3);
    list.insert_rear(4);
    list.insert_rear(5);
    list.insert_front(2);
    list.insert_front(1);

    if (list.first(data)) {
        std::cout << data << " ";
        for (int i = 0; i < list.count() * 3 - 1; i++) if (list.next(data)) std::cout << data << " ";
        std::cout << std::endl;
    }

    if (list.count()) {
        list.first(data);
        if (data % 2 == 0) list.remove();

        for (int i = 0; i < list.count() - 1; i++) {
            list.next(data);
            if (data % 2 == 0) list.remove();
        }
    }

    if (list.first(data)) {
        std::cout << data << " ";
        for (int i = 0; i < list.count() - 1; i++) if (list.next(data)) std::cout << data << " ";
        std::cout << std::endl;
    }

    return 0;
}