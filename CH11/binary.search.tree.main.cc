#include <iostream>
#include <binary.search.tree.hh>

int main() {
    BinarySearchTree<item<int, double>> bst;

    bst.insert({1, 1.34});
    bst.insert({2, 2.96});
    bst.insert({3, 3.14});

    for (int key : {0, 1, 2, 3, 4, 5}) {
        try {
            auto &item = bst.search(key);
            std::cout << "[     ITEM FOUND     ] " << item.key << " " << item.value << std::endl;
        } catch (...) {
            std::cout << "[ ITEM IS NOT FOUND  ] " << key << std::endl;
        }
    }

    return 0;
}
