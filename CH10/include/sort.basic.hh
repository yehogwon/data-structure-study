#ifndef __SORT_BASIC_HH__
#define __SORT_BASIC_HH__

#include <vector>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
std::vector<T> bubble_sort(const std::vector<T> &vec) {
    std::vector<T> sorted(vec);
    for (int i = 0; i < sorted.size(); i++)
        for (int j = 0; j < sorted.size() - i - 1; j++)
            if (sorted[j] > sorted[j + 1])
                swap(sorted[j], sorted[j + 1]);
    return sorted;
}

template <typename T>
std::vector<T> selection_sort(const std::vector<T> &vec) {
    std::vector<T> sorted(vec);
    for (int i = 0; i < sorted.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < sorted.size(); j++)
            if (sorted[j] < sorted[min])
                min = j;
        if (i != min) swap(sorted[i], sorted[min]);
    }
    return sorted;
}

template <typename T>
std::vector<T> insertion_sort(const std::vector<T> &vec) {
    std::vector<T> sorted(vec);
    for (int i = 1; i < sorted.size(); i++) {
        T target = sorted[i];
        int j;
        for (j = i; j > 0 && sorted[j - 1] > target; j--)
            sorted[j] = sorted[j - 1];
        sorted[j] = target;
    }
    return sorted;
}

#endif // __SORT_BASIC_HH__