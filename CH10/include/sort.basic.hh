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
std::vector<T> bubble_sort(std::vector<T> vec) {
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size() - i - 1; j++)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
    return vec;
}

template <typename T>
std::vector<T> selection_sort(std::vector<T> vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[min])
                min = j;
        if (i != min) swap(vec[i], vec[min]);
    }
    return vec;
}

template <typename T>
std::vector<T> insertion_sort(std::vector<T> vec) {
    for (int i = 1; i < vec.size(); i++) {
        T target = vec[i];
        int j;
        for (j = i; j > 0 && vec[j - 1] > target; j--)
            vec[j] = vec[j - 1];
        vec[j] = target;
    }
    return vec;
}

#endif // __SORT_BASIC_HH__