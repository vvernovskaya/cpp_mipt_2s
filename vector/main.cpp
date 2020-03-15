#include <iostream>
#include <string>

const int FIXED_CAP = 8;

template <class T>
class Vect {
public:
    int capacity = FIXED_CAP;
    T* array = new T [capacity];
    int size_v;
    Vect() {
        size_v = 0;
    }
    Vect(int n, T val) {
        size_v = n;
        capacity = n;
        for (int i = 0; i < size_v; i++) {
            array[i] = val;
        }
    }
    ~Vect() {
        delete[] array;
    }

    // Vect(const Vect &other) {}

    int operator[] (int i) {
        if (i >= size_v) {
            std::cerr << "Index out of range" << std::endl;
            return 0;
        }
        else {
            return array[i];
        }
    }

    // int* begin() {}
    // int* end() {}

    int size() {
        return size_v;
    }
    T back() {
        return array[size_v-1]
    }
    void push_back(const int x) {
        if (size_v == capacity) {
            T* new_array = new T[capacity*2];
            for (int i = 0; i < size_v; i++) {
                new_array[i] = array[i];
            }
            new_array[size_v] = x;
            delete [] array;
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
            for (int i = 0; i < size_v-1; i++) {
                new_array[i] = array[i];
            }
            delete [] array;
            array = new_array;
            size_v--;
        }
        else {
            delete &array[size_v-1];
            size_v--;
        }
    }
    void print() {
        std::cout << "[";
        for (int i = 0; i < size_v; i++) {
            std::cout << array[i];
            if (i != size_v-1) {
                std::cout << "; ";
            }
        }
        std::cout << "]" << std::endl;
    }

};

int main() {
    // Initializing different vectors
    Vect<int> a;
    for (int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    a.print();

    Vect<int> b(10, 0);
    b.print();

    // Checking capacity
    /* std::cout << "Current capacity of b when size_v is 10 : " << b.capacity << std::endl;
    b.push_back(10);
    b.print();
    std::cout << "Current capacity of b when size_v is 11 : " << b.capacity << std::endl;
    b.pop_back();
    std::cout << "Current capacity of b when size_v is 10 : " << b.capacity << std::endl; */

    std::cout << "Checking operator[]" << std::endl;
    for (int i = 0; i < a.size_v; i++) {
        std::cout << a.array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Deleting vector b" << std::endl;
    b.~Vect();
    return 0;
}
