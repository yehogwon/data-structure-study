#ifndef __HEAP_HH__
#define __HEAP_HH__

const int MAX_LENGTH = 1000;

template <typename T>
class Heap {
private: 
    struct HeapElement {
        T value;
        int priority; // the lower priority index, the higher precedence

        HeapElement() : value(), priority(-1) {}
        HeapElement(T value, int priority) : value(value), priority(priority) {}
    };

    HeapElement data[MAX_LENGTH];
    int n_data;

    int parent(int i) {
        return (i - 1) / 2;
    }

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

    int higher_child(int i) {
        if (is_leaf(i)) return 0;
        if (no_right_child(i)) return left(i);
        return data[left(i)].priority < data[right(i)].priority ? left(i) : right(i);
    }
public: 
    Heap() : n_data(0) {}

    void insert(T value, int priority) {
        int index = ++n_data;
        HeapElement elem = HeapElement(value, priority);
        while (index > 1 && priority < data[parent(index)].priority) {
            data[index] = data[parent(index)];
            index = parent(index);
        }
        data[index] = elem;
    }

    T remove() {
        T ret = data[1].value;
        HeapElement pivot = data[n_data--];
        int index = 1;
        int child_index;
        while ((child_index = higher_child(index)) && pivot.priority > data[child_index].priority) {
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

#endif // __HEAP_HH__