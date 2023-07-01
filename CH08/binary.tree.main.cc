#include <iostream>
#include "binary.tree.hh"

using inodeptr = nodeptr<int>;

int main() {
    inodeptr bt1 = create_node<int>(), bt2 = create_node<int>(), bt3 = create_node<int>(), bt4 = create_node<int>();

    bt1->data = 1;
    bt2->data = 2;
    bt3->data = 3;
    bt4->data = 4;

    bt1->left = bt2;
    bt1->right = bt3;
    bt2->left = bt4;
    
    // print the tree bt1 in the shape of tree
    std::cout << " ---- TREE ---- " << std::endl;
    std::cout << "      " << bt1->data << std::endl;
    std::cout << "     / \\" << std::endl;
    std::cout << "    " << bt2->data << "   " << bt3->data << std::endl;
    std::cout << "   /" << std::endl;
    std::cout << "  " << bt4->data << std::endl;

    std::cout << bt1->left->data << std::endl;
    std::cout << bt1->left->left->data << std::endl;

    return 0;
}
