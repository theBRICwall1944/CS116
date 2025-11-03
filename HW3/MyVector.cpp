#include <iostream>
#include <stdexcept>
#include "MyVector.h"

MyVector::MyVector (){
    size = 0;
    capacity = 5;
    data = new int[capacity];
}

MyVector::~MyVector(){
    delete[] data;
}

MyVector::MyVector(const MyVector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++){
        data[i]=other.data[i];
    }
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other) return*this;

    delete[] data; 

    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size ; i++){
        data[i] = other.data[i];
    } 
}

void MyVector::resize() {
    capacity *= 2;
    
    int* newData = new int[capacity];

    for (int i = 0; i < size; i++){
        newData[i] = data[i];
    }

    delete[] data;
    
    data = newData;

}

int MyVector::getSize() const{
    return size;
}

int MyVector::getCapacity() const {
    return capacity;
}

bool MyVector::isEmpty() const {
    return size == 0;
}

int& MyVector::at(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("index is out of range");
    }

    return data[index];
}

void MyVector::push_back(const int& element) {
    if (size == capacity){
        resize();
    }

    data[size++] = element;
}

void MyVector::insert(int index, const int& element) {
    if (index < 0 || index > size) {
        throw std:: out_of_range("The index is out of range");
    }

    if (size == capacity) {
        resize();
    }

    for (int i = size; i > index; i--){
        data[i] = data[i-1];
    }

    data[index] = element;
    ++size;
}

void MyVector::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot pop from empty vector");
    }
    --size;
}

int& MyVector::operator[](int index){
    return data[index];
}

int main() {
    MyVector vector;
    int num;

    while (true) {
        char ch;
        if (!(std::cin >> num)) break;
        if (num == -1) break;
        vector.push_back(num);

        if (std::cin.peek() == ',') std::cin >> ch;
    }

    try {
        std::cout << std::endl;

        if (vector.getSize() >= 1) {
            std::cout << vector.at(vector.getSize()  - 1) << " ";
            vector.pop_back();
        }
        if (vector.getSize() >= 1) {
            std::cout << vector.at(vector.getSize() - 1) << std::endl;
            
            vector.pop_back();
        }
        else {
            std::cout << "Not enough elements to print";
        }

        std::cout << std::endl;

        std::cout << vector.getSize() << std::endl;

        for (int i = 0; i < vector.getSize(); i++){
            std::cout <<vector[i] << " ";
        }
    }

    catch (const std::out_of_range& e) {
        std:: cerr << "Error " << e.what() << std::endl;
    }

    return 0;
}