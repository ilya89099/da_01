#pragma once;

#include <iostream>

template <typename T>
class my_vector{
public:
    my_vector() = default;

    my_vector(size_t size)
    : size_(size), capacity_(size), data_(new T[size]) {}

    my_vector(size_t size, T def)
    : size_(size), capacity_(size), data_(new T[size]) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = def;
        }
    }

    my_vector(my_vector&& other)
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    my_vector(const my_vector& other)
    : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_){
        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    ~my_vector() {
        delete data_;
    }

    my_vector& operator = (const my_vector& other) {
        delete data_;
        data_ = new T[other.size_];
        size_ = other.size_;
        capacity_ = other.size_;
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    my_vector& operator = (my_vector&& other) {
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        return *this;
    }

    T& operator[] (size_t index) {
        return data_[index];
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    void push_back(T elem){
        if (size_ == capacity_){
            capacity_ += 5000;
            T* temp = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                temp[i] = data_[i];
            }
            delete[] data_;
            data_ = temp;
        }
        data_[size_++]=elem;
    }

    void shrink_to_fit() {
        if (capacity_ > size_) {
            T* temp = new T[size_];
            std::copy(data_, data_ + size_, temp);
            delete data_;
            data_ = temp;
            capacity_ = size_;
        }
    }



private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
};
