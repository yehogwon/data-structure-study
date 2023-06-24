#include <iostream>
#include "stack.hh"

int main() {
    ArrayStack<int> stack;

    for (int i = 1; i <= 5; i++) stack.push(i);

    while (!stack.empty()) std::cout << stack.pop() << std::endl;

    return 0;
}
