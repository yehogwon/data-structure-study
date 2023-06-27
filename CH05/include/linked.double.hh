#ifndef __LINKED_DOUBLE_HH__
#define __LINKED_DOUBLE_HH__

template <typename T>
class DoublyLinkedList {
private: 
    struct Node { // Doubly linked list
        T data;
        Node *prev, *next;

        Node() : prev(nullptr), next(nullptr) {}
        Node(T data, Node *prev=nullptr, Node *next=nullptr) : data(data), prev(prev), next(next) {}
    };

    Node *head, *cur;
    int n_data;

    bool get(T &value) {
        if (!cur) return false;
        value = cur->data;
        return true;
    }
public: 
    DoublyLinkedList() : head(nullptr), cur(nullptr), n_data(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }

    void insert(T value) {
        Node *p = new Node(value, nullptr, head);
        if (head) head->prev = p;
        head = p;
        n_data++;
    }

    bool first(T &value) {
        cur = head;
        return get(value);
    }

    bool next(T &value) {
        if (!cur || !(cur->next)) return false;
        cur = cur->next;
        return get(value);
    }

    bool previous(T &value) {
        if (!cur || !(cur->prev)) return false;
        cur = cur->prev;
        return get(value);
    }

    int count() {
        return n_data;
    }

    bool empty() {
        return n_data == 0;
    }
};

#endif // __LINKED_DOUBLE_HH__