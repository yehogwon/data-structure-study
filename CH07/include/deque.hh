#ifndef __DEQUE_HH__
#define __DEQUE_HH__

#include <stdexcept>

template <typename T>
class Deque {
private: 
    struct Node { // Doubly linked list
        T data;
        Node *prev, *next;

        Node() : prev(nullptr), next(nullptr) {}
        Node(T data, Node *prev=nullptr, Node *next=nullptr) : data(data), prev(prev), next(next) {}
    };

    Node *front, *rear;
public: 
    Deque() : front(nullptr), rear(nullptr) {}
    
    ~Deque() {
        while (!empty()) {
            remove_front();
        }
    }
    
    void add_front(T data) {
        Node *p = new Node(data, nullptr, front);
        if (empty()) rear = p;
        else front->prev = p;
        front = p;
    }

    void add_rear(T data) {
        Node *p = new Node(data, rear, nullptr);
        if (empty()) front = p;
        else rear->next = p;
        rear = p;
    }

    T remove_front() {
        T val = peek_front();
        Node *p = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        else front->prev = nullptr;
        delete p;
        return val;
    }

    T remove_rear() {
        T val = peek_rear();
        Node *p = rear;
        rear = rear->prev;
        if (rear == nullptr) front = nullptr;
        else rear->next = nullptr;
        delete p;
        return val;
    }

    T peek_front() {
        if (empty()) throw std::out_of_range("The deque is empty.");
        return front->data;
    }

    T peek_rear() {
        if (empty()) throw std::out_of_range("The deque is empty.");
        return rear->data;
    }

    bool empty() {
        return front == nullptr;
    }
};

#endif // __DEQUE_HH__