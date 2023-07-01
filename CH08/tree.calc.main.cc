#include <iostream>
#include "tree.calc.hh"

int main() {
    std::string infix = "(1+2)*7";
    std::vector<std::string> postfix = infix_to_postfix(infix);
    nodeptr<std::string> root = postfix_to_tree(postfix);

    std::cout << "ROOT: " << root->data << std::endl;
    preorder_traverse<std::string>(root, [](std::string &data) { std::cout << data << std::endl; });
    std::cout << "==============================" << std::endl;
    inorder_traverse<std::string>(root, [](std::string &data) { std::cout << data << std::endl; });
    std::cout << "==============================" << std::endl;
    postorder_traverse<std::string>(root, [](std::string &data) { std::cout << data << std::endl; });

    //      +
    //     / \
    //    1   *
    //       / \
    //      2   7

    std::cout << "EVALUATION: " << evaluate(root) << std::endl;

    return 0;
}
