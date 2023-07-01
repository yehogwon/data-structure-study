#ifndef __BINARY_TREE_TRAVERSE_HH__
#define __BINARY_TREE_TRAVERSE_HH__

#include <functional>

template <typename T>
void preorder_traverse(nodeptr<T> &root, std::function<void(T&)> visit) {
    if (!root) return;
    visit(root->data);
    preorder_traverse(root->left, visit);
    preorder_traverse(root->right, visit);
}

template <typename T>
void inorder_traverse(nodeptr<T> &root, std::function<void(T&)> visit) {
    if (!root) return;
    inorder_traverse(root->left, visit);
    visit(root->data);
    inorder_traverse(root->right, visit);
}

template <typename T>
void postorder_traverse(nodeptr<T> &root, std::function<void(T&)> visit) {
    if (!root) return;
    postorder_traverse(root->left, visit);
    postorder_traverse(root->right, visit);
    visit(root->data);
}

#endif // __BINARY_TREE_TRAVERSE_HH__