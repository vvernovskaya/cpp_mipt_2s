#include <iostream>

const int FIXED_CAP = 8;

class Vect {
public:
    int capacity = FIXED_CAP;
    int* array = new int [capacity];
    int size_v;
    Vect() {
        size_v = 0;
    }
    explicit Vect(int n) {
        size_v = n;
        capacity = (n / 8 + 1) * FIXED_CAP;
    }
    int operator[] (int i) {
        if (i >= size_v) {
            std::cerr << "Index out of range";
            return 0;
        }
        else {
            return array[i];
        }
    }
    int* begin() {
        return &array[0];
    }
    int* end() {
        return &array[size_v-1];
    }
    int size() {
        return size_v;
    }
    void push_back(const int x) {
        if (size_v == capacity) {
            capacity = capacity+FIXED_CAP;
            int* new_array = new int[capacity];
            for (int i = 0; i < size_v; i++) {
                new_array[i] = array[i];
            }
            new_array[size_v] = x;
            delete [] array;
            array = new_array;
            size_v++;
        }
        else {
            array[size_v] = x;
            size_v++;
        }
    }
    void pop_back() {
        if (size_v - 1 == capacity - FIXED_CAP) {
            capacity = capacity-FIXED_CAP;
            int* new_array = new int[capacity];
            for (int i = 0; i < size_v-1; i++) {
                new_array[i] = array[i];
            }
            delete [] array;
            array = new_array;
            size_v--;
        }
        else {
            array[size_v-1] = 0;
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
    Vect a;
    a.push_back(5);
    a.push_back(8);
    a.push_back(10);
    a.push_back(19);
    a.push_back(10);
    a.push_back(9);
    a.push_back(17);
    a.push_back(14);
    std::cout << "current capacity when size == 8 is " << a.capacity << std::endl;
    a.push_back(10);
    std::cout << "current capacity when size == 9 is " << a.capacity << std::endl;
    a.print();
    for (int i = 0; i < a.size_v; i++) {
        std::cout << a.array[i] << " ";
    }
    a.pop_back();
    a.print();
    std::cout << std::endl;
    std::cout << "current capacity when size == 8 is " << a.capacity << std::endl;
    return 0;
}
