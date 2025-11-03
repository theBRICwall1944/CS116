#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept> // Use it for std::out_of_range

class MyVector {
private:
    int* data;
    int size;
    int capacity;

    // Private helper function for resizing
    void resize();

public:
    // 1. Constructors, Destructor
    MyVector();
    ~MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    // 2. Basic Accessors
    int    getSize() const;
    int    getCapacity() const;
    bool isEmpty() const;
    
    // Returns a reference to the element at the specified index with bounds checking
    int& at(int index);

    // 3. Core Functionality: Insertion and Resizing
    void push_back(const int& element);
    
    // Inserts element at a specific index
    void insert(int index, const int& element);

    // 4. Removal
    void pop_back();

    // 5. Overloaded Operator (NO bounds checking)
    int& operator[](int index);
};

#endif // MYVECTOR_H