#ifndef __BINARY_TREE_HH__
#define __BINARY_TREE_HH__

template <typename T>
struct node {
    T data;
    node<T> *left, *right;

    node() : left(nullptr), right(nullptr) {}
    node(T data, node<T> *left=nullptr, node<T> *right=nullptr) : data(data), left(left), right(right) {}
    ~node() {
        delete left;
        delete right;
    }
};

#endif // __BINARY_TREE_HH__