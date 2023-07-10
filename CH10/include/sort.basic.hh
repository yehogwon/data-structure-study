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
void bubble_sort_inplace(std::vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size() - i - 1; j++)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
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
void selection_sort_inplace(std::vector<T> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[min])
                min = j;
        if (i != min) swap(vec[i], vec[min]);
    }
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

template <typename T>
void insertion_sort_inplace(std::vector<T> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        T target = vec[i];
        int j;
        for (j = i; j > 0 && vec[j - 1] > target; j--)
            vec[j] = vec[j - 1];
        vec[j] = target;
    }
}

#endif // __SORT_BASIC_HH__