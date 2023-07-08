#ifndef __SORT_ADVANCE_HH__
#define __SORT_ADVANCE_HH__

#include "sort.basic.hh"
#include "heap.hh"

template <typename T>
using heap = CompHeap<T>;

template <typename T>
std::vector<T> heap_sort(const std::vector<T> &vec) {
    heap<T> heap_([](const T &a, const T &b) { return a < b; });
    for (const T &e : vec) heap_.insert(e);

    std::vector<T> sorted;
    while (!heap_.empty()) sorted.push_back(heap_.remove());
    return sorted;
}

template <typename T>
void heap_sort_inplace(std::vector<T> &vec) {
    heap<T> heap_([](const T &a, const T &b) { return a < b; });
    while (!vec.empty()) heap_.insert(vec.back()), vec.pop_back();
    while (!heap_.empty()) vec.push_back(heap_.remove());
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
std::vector<T> merge_sort(const std::vector<T> &vec) {
    if (vec.size() <= 1) return vec;
    int mid = vec.size() / 2;
    return merge(merge_sort(std::vector<T>(vec.begin(), vec.begin() + mid)), merge_sort(std::vector<T>(vec.begin() + mid, vec.end())));
}

template <typename T>
int partition(std::vector<T> &vec) {
    const T &pivot = vec[0];
    int low = 1, high = vec.size() - 1;
    while (low <= high) {
        while (pivot >= vec[low] && low <= vec.size() - 1) low++;
        while (pivot <= vec[high] && high >= 1) high--;
        if (low <= high) swap(vec[low], vec[high]);
    }
    if (high != 0) swap(vec[0], vec[high]);
    return high;
}

template <typename T>
std::vector<T> quick_sort(const std::vector<T> &vec__) {
    if (vec__.size() <= 1) return vec__;
    std::vector<T> vec = vec__;
    int pivot_index = partition(vec);
    const std::vector<T> &&left = quick_sort(std::vector<T>(vec.begin(), vec.begin() + pivot_index));
    const std::vector<T> &&right = quick_sort(std::vector<T>(vec.begin() + pivot_index + 1, vec.end()));
    std::vector<T> sorted = left;
    sorted.push_back(vec[pivot_index]);
    sorted.insert(sorted.end(), right.begin(), right.end());
    return sorted;
}

#endif // __SORT_ADVANCE_HH__