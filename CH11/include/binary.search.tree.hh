#ifndef __BINARY_SEARCH_TREE_HH__
#define __BINARY_SEARCH_TREE_HH__

#include "binary.tree.hh"

template <typename K, typename V>
struct item {
    using key_type = K;
    using value_type = V;
    key_type key;
    value_type value;
};

template <typename T>
class BinarySearchTree {
    using item_type = T;
    using key_type = typename item_type::key_type;
    using value_type = typename item_type::value_type;
    using nodeptr = node<item_type>*;
private: 
    nodeptr root;

    nodeptr& search_(const key_type &key) {
        nodeptr cur = root;
        while (cur) {
            if (key == cur->data.key) return cur;
            if (key < cur->data.key) cur = cur->left;
            else cur = cur->right;
        }
        throw std::runtime_error("Key not found");
    }

    nodeptr& min(const nodeptr &root) {
        nodeptr cur = root;
        while (cur->left) cur = cur->left;
        return cur;
    }

    nodeptr& max(const nodeptr &root) {
        nodeptr cur = root;
        while (cur->right) cur = cur->right;
        return cur;
    }

public: 
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        delete root; // deletes child nodes recursively
    }

    void insert(const item_type &item) {
        nodeptr p = new node<item_type>(item);
        nodeptr prev = nullptr;
        nodeptr cur = root;
        
        while (cur) {
            if (item.key == cur->data.key) throw std::runtime_error("Duplicate key");
            
            prev = cur;
            if (item.key < cur->data.key) {
                if (cur->left) cur = cur->left;
                else break;
            } else {
                if (cur->right) cur = cur->right;
                else break;
            }
        }
        
        if (!prev) root = p;
        else if (item.key < prev->data.key) prev->left = p;
        else prev->right = p;
    }

    item_type& search(const key_type &key) {
        return search_(key)->data;
    }

    // FIXME: remove function is not working properly
    void remove(const key_type &key) {
        nodeptr &del = search_(key);
        nodeptr tmp = del;

        if (del->left && del->right) { // two children
            nodeptr target = min(del->right);
            del = target;
        } else if (del->left) { // left only
            del = del->left;
        } else if (del->right) { // right only
            del = del->right;
        }
        
        delete tmp;
    }
};

#endif // __BINARY_SEARCH_TREE_HH__