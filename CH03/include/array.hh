#ifndef __ARRAY_HH__
#define __ARRAY_HH__

const int MAX_LENGTH = 1000;

template <typename T>
class ArrayList {
private: 
    T data[MAX_LENGTH];
    int n_data, cursor;

    bool get(T &value) {
        if (cursor < 0 || cursor >= n_data || n_data == 0) return false;
        value = data[cursor];
        return true;
    }
public: 
    ArrayList() : n_data(0), cursor(0) {}

    void insert(T value) {
        data[n_data++] = value;
    }

    bool first(T &value) {
        cursor = 0;
        return get(value);
    }

    bool next(T &value) {
        cursor++;
        return get(value);
    }

    T remove() {
        T value = data[cursor];
        for (int i = cursor; i < n_data - 1; i++) data[i] = data[i + 1];
        n_data--;
        cursor--;
        return value;
    }
    
    int count() {
        return n_data;
    }
};

#endif // __ARRAY_HH__