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

template <typename T>
void selection_sort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (i != min) swap(arr[i], arr[min]);
    }
}

#endif // __BASIC_SORT_HH__