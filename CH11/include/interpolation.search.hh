#ifndef __INTERPOLATION_SEARCH_HH__
#define __INTERPOLATION_SEARCH_HH__

#include <stdexcept>

template <typename K, typename V>
struct item {
    using key_type = K;
    using value_type = V;
    key_type key;
    value_type value;
};

template <typename E>
E& interpolation_search(E *arr, typename E::key_type target, int start, int end) {
    if (start > end || arr[start].key > target || arr[end].key < target) throw std::out_of_range("target not found");
    int pivot = (static_cast<double>(target - arr[start].key) / (arr[end].key - arr[start].key)) * (end - start) + start;
    if (arr[pivot].key == target) return arr[pivot];
    else if (arr[pivot].key > target) return interpolation_search(arr, target, start, pivot - 1);
    else return interpolation_search(arr, target, pivot + 1, end);
}

#endif // __INTERPOLATION_SEARCH_HH__