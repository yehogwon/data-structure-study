#ifndef __LINKED_CIRCULAR_HH__
#define __LINKED_CIRCULAR_HH__

template <typename T>
class CircularLinkedList {
private: 
    struct Node {
        T data;
        Node *next;

        Node() : next(nullptr) {}
        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node *next) : data(data), next(next) {}
    };

    Node *tail, *prev, *cur;
    int n_data;

    bool get(T &value) {
        if (!tail) return false;
        value = cur->data;
        return true;
    }
public:
    CircularLinkedList() : tail(nullptr), prev(nullptr), cur(nullptr), n_data(0) {}

    ~CircularLinkedList() {
    }

    void insert_rear(T value) {
        Node *p = new Node(value);
        if (tail == nullptr) { // empty
            tail = p;
            tail->next = p;
        } else {
            p->next = tail->next;
            tail->next = p;
            tail = p;
        }
        n_data++;
    }

    void insert_front(T value) {
        Node *p = new Node(value);
        if (tail == nullptr) { // empty
            tail = p;
            tail->next = p;
        } else {
            p->next = tail->next;
            tail->next = p;
        }
        n_data++;
    }

    bool first(T &value) {
        prev = tail, cur = tail->next;
        return get(value);
    }

    bool next(T &value) {
        prev = cur, cur = cur->next;
        return get(value);
    }

    T remove() {
        Node *p = cur;
        T value = cur->data;
        if (cur == tail) {
            if (tail == tail->next) tail = nullptr;
            else tail = prev;
        }
        prev->next = prev->next->next;
        cur = prev;
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

#endif // __LINKED_CIRCULAR_HH__