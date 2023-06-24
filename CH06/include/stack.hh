#ifndef __STACK_HH__
#define __STACK_HH__

#include <stdexcept>

const int MAX_LENGTH = 1000;

template <typename T>
class ArrayStack {
private: 
    T data[MAX_LENGTH];
    int top_index;
public: 
    ArrayStack() : top_index(-1) {}

    void push(T val) {
        data[++top_index] = val;
    }

    T pop() {
        if (empty()) throw std::out_of_range("The stack is empty.");
        return data[top_index--];
    }

    T peek() {
        if (empty()) throw std::out_of_range("The stack is empty.");
        return data[top_index];
    }

    bool empty() {
        return top_index == -1;
    }
};

template <typename T>
class LinkedListStack {
private: 
    struct Node {
        T data;
        Node *next;

        Node() : next(nullptr) {}
        Node(T data) : data(data), next(nullptr) {}
        Node(T data, Node *next) : data(data), next(next) {}
    };

    Node *top;
public: 
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack() {
        while (!empty()) pop();
    }

    void push(T val) {
        top = new Node(val, top);
    }

    T pop() {
        T val = peek();
        Node *p = top;
        top = top->next;
        delete p;
        return val;
    }

    T peek() {
        if (empty()) throw std::out_of_range("The stack is empty.");
        return top->data;
    }

    bool empty() {
        return top == nullptr;
    }
};

#endif // __STACK_HH__