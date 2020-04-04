#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int FIXED_CAP = 8;

template <class T>
class Iterator {
private:
    T* it;
public:
    Iterator(T* arr) {
        it = arr;
    }
    void operator+= (int n) {
        it += n;
    }
    void operator-= (int n) {
        it -= n;
    }
    Iterator operator+ (int n) const {
        return it + n;
    }
    Iterator operator- (int n) const {
        return it - n;
    }
    void operator-- () {
        it--;
    }
    void operator++ () {
        it++;
    }
    std::ptrdiff_t operator- (const Iterator other) {
        return it - other.it;
    }
    void operator= (const Iterator other) {
        it = other.it;
    }
    bool operator== (const Iterator other) {
        if (other.it == it) {
            return true;
        }
        else { return false; }
    }
    bool operator!= (const Iterator other) {
        if (other.it != it) {
            return true;
        }
        else { return false; }
    }
    T operator* (int n) {
        return *it;
    }
};

template <class T>
class Vect {
public:
    int capacity = FIXED_CAP;
    T* array = nullptr;
    int size_v;
    Vect() {
        size_v = 0;
        array = new T[capacity];
    }
    Vect(int n, T val) {
        size_v = n;
        capacity = n;
        array = new T[capacity];
        for (int i = 0; i < size_v; i++) {
            array[i] = val;
        }
    }
    Vect(const Vect<T>& other) {
        size_v = other.size_v;
        capacity = other.capacity;
        array = new T[capacity];
        for (int i = 0; i < size_v; i++) {
            array[i] = other.array[i];
        }
    }
    ~Vect() {
        delete[] array;
        array = nullptr;
    }

    void operator= (const Vect& other) {
        size_v = other.size_v;
        delete[] array;
        capacity = other.capacity;
        T* array = new T[capacity];
        for (int i = 0; i < size_v; i++) {
            array[i] = other.array[i];
        }
    }

    T operator[] (int i) {
        if (i >= size_v) {
            std::cerr << "Index out of range" << std::endl;
            return 0;
        }
        else {
            return array[i];
        }
    }
    Iterator<T> begin() {
        return Iterator<T>(array);
    }
    Iterator<T> end() {
        return Iterator<T>(array + size_v);
    }
    int size() {
        return size_v;
    }
    T back() {
        return array[size_v - 1];
    }
    void push_back(const int x) {
        if (size_v == capacity) {
            T* new_array = new T[capacity * 2];
            for (int i = 0; i < size_v; i++) {
                new_array[i] = array[i];
            }
            new_array[size_v] = x;
            delete[] array;
            array = new_array;
            size_v++;
            capacity *= 2;
        }
        else {
            array[size_v] = x;
            size_v++;
        }
    }
    void pop_back() {
        if (size_v - 1 == capacity / 2) {
            capacity /= 2;
            T* new_array = new T[capacity];
            for (int i = 0; i < size_v - 1; i++) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            size_v--;
        }
        else {
            size_v--;
        }
    }
    void print() {
        std::cout << "[";
        for (int i = 0; i < size_v; i++) {
            std::cout << array[i];
            if (i != size_v - 1) {
                std::cout << "; ";
            }
        }
        std::cout << "]" << std::endl;
    }

};

int main() {
    Vect<int> a;
    a.push_back(2);
    a.push_back(5);
    a.push_back(2);
    a.push_back(8);
    a.push_back(4);
    a.push_back(9);
    a.push_back(3);
    a.print();
    Vect<int> b(a);
    //std::sort(a.begin(), a.end());
    b.print();
    return 0;
}