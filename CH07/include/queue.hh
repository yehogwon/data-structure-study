#ifndef __QUEUE_HH__
#define __QUEUE_HH__

#include <stdexcept>

const int QUEUE_MAX_LENGTH = 1000;

template <typename T>
class ArrayQueue {
private: 
    T data[QUEUE_MAX_LENGTH];
    int front, rear;
    
    int index(int i) {
        return i % QUEUE_MAX_LENGTH;
    }

    int& next(int &i) {
        return i = index(i + 1);
    }

public: 
    ArrayQueue() : front(0), rear(0) {}

    void enqueue(T data) {
        if (index(rear + 1) == index(front)) throw std::out_of_range("The queue is full.");
        this->data[next(rear)] = data;
    }

    T dequeue() {
        T val = peek();
        next(front);
        return val;
    }

    T peek() {
        if (empty()) throw std::out_of_range("The queue is empty.");
        return this->data[index(front + 1)];
    }

    bool empty() {
        return index(front) == index(rear);
    }
};

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