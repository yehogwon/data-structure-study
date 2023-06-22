#include <iostream>
#include "linked.hh"

using List = LinkedList<int>;

int main() {
    List list;
    int data;
    
    list.insert(11);
    list.insert(11);
    list.insert(22);
    list.insert(22);
    list.insert(33);

    std::cout << "current size: " << list.count() << std::endl;

    if (list.first(data)) {
        std::cout << data << " ";
        while (list.next(data)) std::cout << data << " ";
    }
    std::cout << std::endl;

    if (list.first(data)) {
        if (data == 22) list.remove();
        while (list.next(data)) if (data == 22) list.remove();
    }

    std::cout << "current size: " << list.count() << std::endl;

    if (list.first(data)) {
        std::cout << data << " ";
        while (list.next(data)) std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}
