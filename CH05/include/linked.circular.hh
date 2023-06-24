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
        return false;
    }
public:
    CircularLinkedList() : tail(nullptr), prev(nullptr), cur(nullptr), n_data(0) {}

    ~CircularLinkedList() {
        Node *p = tail->next; // head
        while (p != tail) {
            Node *next = p->next;
            delete p;
            p = next;
        }
        delete tail;
    }

    void insert(T value) {
        Node *on = tail;
        Node *p = new Node(value);
        
        if (on == nullptr) {
            tail = p;
            tail->next = p;
        } else {
            p->next = tail->next;
            tail->next = p;
            tail = p;
        }
    }

    void insert_front(T value) {
        // TODO: implement here
    }

    bool first(T &value) {
        // TODO: implement here
    }

    bool next(T &value) {
        // TODO: implement here
    }

    T remove();

    int count() {
        return n_data;
    }
};

#endif __LINKED_CIRCULAR_HH__ // __LINKED_CIRCULAR_HH__