#ifndef __SORT_ADVANCE_HH__
#define __SORT_ADVANCE_HH__

#include "heap.hh"

template <typename T>
using heap = CompHeap<T>;

template <typename T>
std::vector<T> heap_sort(std::vector<T> vec) {
    heap<T> heap_([](const T &a, const T &b) { return a < b; });
    for (const T &e : vec) heap_.insert(e);

    std::vector<T> sorted;
    while (!heap_.empty()) sorted.push_back(heap_.remove());
    return sorted;
}

#endif // __SORT_ADVANCE_HH__