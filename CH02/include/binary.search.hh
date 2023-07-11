#ifndef __BINARY_SEARCH_HH__
#define __BINARY_SEARCH_HH__

template <typename T>
int binary_search(const T *arr, int target, int start, int end) {
    if (start > end) return -1;
    int m = start + (end - start) / 2; // to avoid overflow
    if (arr[m] == target) return m;
    else if (arr[m] > target) return binary_search(arr, target, start, m - 1);
    else return binary_search(arr, target, m + 1, end);
}

#endif // __BINARY_SEARCH_HH__