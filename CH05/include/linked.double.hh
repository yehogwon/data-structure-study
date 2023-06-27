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

template <typename T>
class DummyDoublyLinkedList {
private: 
    struct Node { // Doubly linked list
        T data;
        Node *prev, *next;

        Node() : prev(nullptr), next(nullptr) {}
        Node(T data, Node *prev=nullptr, Node *next=nullptr) : data(data), prev(prev), next(next) {}
    };

    Node *head, *tail, *cur;
    int n_data;

    bool get(T &value) {
        if (!cur) return false;
        value = cur->data;
        return true;
    }
public: 
    DummyDoublyLinkedList() : head(new Node), tail(new Node), cur(nullptr), n_data(0) {
        head->next = tail;
        tail->prev = head;
    }

    ~DummyDoublyLinkedList() {
        while (head) {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }

    void insert(T value) {
        Node *p = new Node(value, tail->prev, tail);
        tail->prev->next = p;
        tail->prev = p;
        n_data++;
    }

    bool first(T &value) {
        if (n_data == 0) return false;
        cur = head->next;
        return get(value);
    }

    bool next(T &value) {
        if (cur == tail || cur->next == tail) return false;
        cur = cur->next;
        return get(value);
    }

    bool previous(T &value) {
        if (cur == head || cur->prev == head) return false;
        cur = cur->prev;
        return get(value);
    }

    T remove() {
        Node *p = cur;
        T value = p->data;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->prev;
        delete p;
        n_data--;
        return value;
    }

    int count() {
        return n_data;
    }

    bool empty() {
        return n_data == 0;
    }
};

#endif // __LINKED_DOUBLE_HH__