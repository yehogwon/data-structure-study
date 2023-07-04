#ifndef __PRIORITY_QUEUE_HH__
#define __PRIORITY_QUEUE_HH__

#include "heap.hh"

template <typename T>
class PriorityQueue : public CompHeap<T> {
    using data_type = T;
public: 
    PriorityQueue(std::function<bool(const data_type&, const data_type&)> compare) : CompHeap<T>(compare) {}

    void enqueue(const T &value) {
        CompHeap<T>::insert(value);
    }

    T dequeue() {
        return CompHeap<T>::remove();
    }

    bool empty() {
        return CompHeap<T>::empty();
    }
};

#endif // __PRIORITY_QUEUE_HH__