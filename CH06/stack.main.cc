#include <iostream>
#include "stack.hh"

int main() {
    std::cout << " ==== Array-based Stack ==== " << std::endl;
    ArrayStack<int> a_stack;
    for (int i = 1; i <= 5; i++) a_stack.push(i);
    while (!a_stack.empty()) std::cout << a_stack.pop() << " ";
    std::cout << std::endl;
    
    std::cout << " ==== Linked-list-based Stack ==== " << std::endl;
    LinkedListStack<int> l_stack;
    for (int i = 1; i <= 5; i++) l_stack.push(i);
    while (!l_stack.empty()) std::cout << l_stack.pop() << " ";
    std::cout << std::endl;

    return 0;
}
