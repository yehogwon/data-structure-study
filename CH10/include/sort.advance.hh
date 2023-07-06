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

template <typename T>
std::vector<T> merge(const std::vector<T> &left, const std::vector<T> &right) {
    if (left.empty()) return right;
    if (right.empty()) return left;
    std::vector<T> merged;
    for (int i = 0, j = 0; i < left.size() || j < right.size();) {
        if (i == left.size()) merged.push_back(right[j++]);
        else if (j == right.size()) merged.push_back(left[i++]);
        else if (left[i] < right[j]) merged.push_back(left[i++]);
        else merged.push_back(right[j++]);
    }
    return merged;
}

template <typename T>
std::vector<T> merge_sort(std::vector<T> vec) {
    if (vec.size() <= 1) return vec;
    int mid = vec.size() / 2;
    return merge(merge_sort(std::vector<T>(vec.begin(), vec.begin() + mid)), merge_sort(std::vector<T>(vec.begin() + mid, vec.end())));
}

#endif // __SORT_ADVANCE_HH__