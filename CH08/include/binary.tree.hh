#ifndef __BINARY_TREE_HH__
#define __BINARY_TREE_HH__

#include <memory>

template <typename T>
struct __BinaryTreeNode;

template <typename T>
class nodeptr : public std::shared_ptr<__BinaryTreeNode<T>> {
public: 
    nodeptr() : std::shared_ptr<__BinaryTreeNode<T>>(new __BinaryTreeNode<T>) {}
    nodeptr(__BinaryTreeNode<T> *ptr) : std::shared_ptr<__BinaryTreeNode<T>>(ptr) {}
};

template <typename T>
struct __BinaryTreeNode {
    T data;
    nodeptr<T> left, right;

    __BinaryTreeNode() : left(nullptr), right(nullptr) {}
    __BinaryTreeNode(T data, nodeptr<T> *left=nullptr, nodeptr<T> *right=nullptr) : data(data), left(left), right(right) {}
};

#endif // __BINARY_TREE_HH__