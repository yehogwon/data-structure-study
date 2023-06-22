#ifndef __LINKED_HH__
#define __LINKED_HH__

#include <functional>


template <typename T>
class LinkedList {
private: 
    struct Node {
        T data;
        Node *next;

        Node() : next(nullptr) {}
        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node *next) : data(data), next(next) {}
    };

    using criteria = std::function<bool(T&, T&)>;

    Node *head, *prev, *cur;
    int n_data;

    criteria comp;

    bool get(T &value) {
        value = cur->data;
        return true;
    }
public: 
    LinkedList(criteria comp=[](T &x, T &y) { return true; }) : head(new Node), prev(nullptr), cur(nullptr), n_data(0), comp(comp) {}
    
    ~LinkedList() {
        Node *p = head;
        while (p != nullptr) {
            Node *next = p->next;
            delete p;
            p = next;
        }
    }

    void insert(T value) {
        Node *p = new Node(value);

        Node *search = head;
        while (search->next && comp(value, search->next->data)) search = search->next;

        p->next = search->next;
        search->next = p;

        n_data++;
    }

    bool first(T &value) {
        if (!head || !(head->next)) return false;
        prev = head, cur = head->next;
        return get(value);
    }

    bool next(T &value) {
        if (!cur || !(cur->next)) return false;
        prev = cur;
        cur = cur->next;
        return get(value);
    }

    T remove() {
        T value = cur->data;
        prev->next = cur->next;
        delete cur;
        cur = prev;
        n_data--;
        return value;
    }

    int count() {
        return n_data;
    }
};

#endif // __LINKED_HH__