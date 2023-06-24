#ifndef __QUEUE_HH__
#define __QUEUE_HH__

#include <stdexcept>

template <typename T>
class LinkedListQueue {
private: 
    struct Node {
        T data;
        Node *next;

        Node() : next(nullptr) {}
        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node *next) : data(data), next(next) {}
    };

    Node *front, *rear;
public: 
    LinkedListQueue() : front(nullptr), rear(nullptr) {}
    
    ~LinkedListQueue() {
        while (!empty()) {
            dequeue();
        }
    }

    void enqueue(T data) {
        Node *p = new Node(data);
        if (front) {
            rear->next = p;
            rear = p;
        } else {
            front = rear = p;
        }
    }

    T dequeue() {
        if (empty()) throw std::out_of_range("The queue is empty.");
        T val = front->data;
        Node *p = front;
        front = front->next;
        delete p;
        return val;
    }
    
    T peek() {
        return front->data;
    }

    bool empty() {
        return front == nullptr;
    }
};

#endif // __QUEUE_HH__