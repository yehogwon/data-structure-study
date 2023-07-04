#ifndef __HEAP_HH__
#define __HEAP_HH__

#include <functional>

const int MAX_LENGTH = 1000;

template <typename T>
struct PriorityElement {
    T value;
    int priority; // the lower priority index, the higher precedence

    PriorityElement() : value(), priority(-1) {}
    PriorityElement(T value, int priority) : value(value), priority(priority) {}

    bool operator<(const PriorityElement& other) {
        return priority < other.priority;
    }

    bool operator>(const PriorityElement& other) {
        return priority > other.priority;
    }
    
    bool operator>=(const PriorityElement& other) {
        return priority >= other.priority;
    }

    bool operator<=(const PriorityElement& other) {
        return priority <= other.priority;
    }
};

template <typename T>
struct ComparisonElement {
    T value;
    std::function<bool(const T&, const T&)> compare; // returns (the former) > (the latter)

    ComparisonElement() : value(), compare([](const T &a, const T &b) { return true; }) {}
    ComparisonElement(T value, std::function<bool(const T&, const T&)> compare) : value(value), compare(compare) {}

    bool operator<(const ComparisonElement& other) {
        return compare(value, other.value);
    }

    bool operator>(const ComparisonElement& other) {
        return compare(other.value, value);
    }
    
    bool operator>=(const ComparisonElement& other) {
        return !compare(value, other.value);
    }

    bool operator<=(const ComparisonElement& other) {
        return !compare(other.value, value);
    }
};

template <typename T_, typename Elem_>
class Heap {
private: 
    using data_type = T_;
    using element_type = Elem_;

    int left(int i) {
        return 2 * i;
    }

    int right(int i) {
        return left(i) + 1;
    }

    bool is_leaf(int i) {
        return left(i) > n_data;
    }

    bool no_right_child(int i) {
        return right(i) > n_data;
    }
protected: 
    element_type data[MAX_LENGTH];
    int n_data;
    
    int parent(int i) {
        return (i - 1) / 2;
    }

    int higher_child(int i) {
        if (is_leaf(i)) return 0;
        if (no_right_child(i)) return left(i);
        return data[left(i)] < data[right(i)] ? left(i) : right(i);
    }
public: 
    Heap() : n_data(0) {}

    void insert(data_type value, int priority) {
        int index = ++n_data;
        element_type elem = element_type(value, priority);
        while (index > 1 && elem < data[parent(index)]) {
            data[index] = data[parent(index)];
            index = parent(index);
        }
        data[index] = elem;
    }

    data_type remove() {
        data_type ret = data[1].value;
        element_type pivot = data[n_data--];
        int index = 1;
        int child_index;
        while ((child_index = higher_child(index)) && pivot > data[child_index]) {
            data[index] = data[child_index];
            index = child_index;
        }
        data[index] = pivot;
        return ret;
    }

    bool empty() {
        return n_data == 0;
    }
};

template <typename T_, typename Elem_>
class ComparisonHeap : public Heap<T_, Elem_> {
private: 
    using data_type = T_;
    using element_type = Elem_;

    std::function<bool(const data_type&, const data_type&)> compare_;
public: 
    ComparisonHeap(std::function<bool(const data_type&, const data_type&)> compare) : Heap<data_type, element_type>(), compare_(compare) {}

    void insert(data_type value) {
        int index = ++(this->n_data);
        element_type elem = element_type(value, compare_);
        while (index > 1 && elem < (this->data)[this->parent(index)]) {
            (this->data)[index] = (this->data)[this->parent(index)];
            index = this->parent(index);
        }
        (this->data)[index] = elem;
    }

    data_type remove() {
        data_type ret = (this->data)[1].value;
        element_type pivot = (this->data)[(this->n_data)--];
        int index = 1;
        int child_index;
        while ((child_index = this->higher_child(index)) && pivot > (this->data)[child_index]) {
            (this->data)[index] = (this->data)[child_index];
            index = child_index;
        }
        (this->data)[index] = pivot;
        return ret;
    }
};

template <typename T>
using PriorHeap = Heap<T, PriorityElement<T>>;

template <typename T>
using CompHeap = ComparisonHeap<T, ComparisonElement<T>>;

#endif // __HEAP_HH__