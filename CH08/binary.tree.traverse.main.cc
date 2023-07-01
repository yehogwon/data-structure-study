#include <iostream>
#include "binary.tree.hh"
#include "binary.tree.traverse.hh"

int main() {
    node<int> *bt1 = new node<int>, *bt2 = new node<int>, *bt3 = new node<int>, *bt4 = new node<int>, *bt5 = new node<int>, *bt6 = new node<int>;

    bt1->data = 1;
    bt2->data = 2;
    bt3->data = 3;
    bt4->data = 4;
    bt5->data = 5;
    bt6->data = 6;
    
    bt1->left = bt2;
    bt1->right = bt3;
    bt2->left = bt4;
    bt2->right = bt5;
    bt3->right = bt6;

    std::cout << " == Preorder traverse == " << std::endl;
    preorder_traverse<int>(bt1, [](int &data) { std::cout << data << std::endl; });
    std::cout << " == Inorder traverse == " << std::endl;
    inorder_traverse<int>(bt1, [](int &data) { std::cout << data << std::endl; });
    std::cout << " == Postorder traverse == " << std::endl;
    postorder_traverse<int>(bt1, [](int &data) { std::cout << data << std::endl; });

    delete bt1;

    return 0;
}
