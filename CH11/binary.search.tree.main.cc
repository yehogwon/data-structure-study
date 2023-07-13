#include <iostream>
#include <binary.search.tree.hh>

int main() {
    BinarySearchTree<item<int, double>> bst;

    bst.insert({0, 0.12});
    bst.insert({1, 1.34});
    bst.insert({3, 3.14});
    bst.insert({4, 4.56});
    bst.insert({7, 7.22});
    bst.insert({8, 8.37});

    for (int key : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        try {
            auto &item = bst.search(key);
            std::cout << "[      ITEM FOUND     ] " << item.key << " " << item.value << std::endl;
        } catch (...) {
            std::cout << "[  ITEM IS NOT FOUND  ] " << key << std::endl;
        }
    }

    return 0;
}
