#ifndef __BASIC_SORT_HH__
#define __BASIC_SORT_HH__

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void bubble_sort(T *arr, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

#endif // __BASIC_SORT_HH__