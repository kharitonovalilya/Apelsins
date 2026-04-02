#include "safe_vector.h"
template <typename T>
SafeVector<T>::SafeVector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
SafeVector<T>::SafeVector(size_t count) : size_(count), capacity_(count) {
    data_ = new T[count];
}

template <typename T>
SafeVector<T>::SafeVector(const SafeVector& other)
    : size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
SafeVector<T>::~SafeVector() {
    delete[] data_;
}

template <typename T>
SafeVector<T>& SafeVector<T>::operator=(const SafeVector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template <typename T>
T& SafeVector<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
const T& SafeVector<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T>
T& SafeVector<T>::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
const T& SafeVector<T>::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
void SafeVector<T>::push_back(const T& value) {
    if (size_ >= capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
}

template <typename T>
void SafeVector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= capacity_)
        return;

    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
T* SafeVector<T>::begin() noexcept {
    return data_;
}

template <typename T>
T* SafeVector<T>::end() noexcept {
    return data_ + size_;
}

template <typename T>
const T* SafeVector<T>::begin() const noexcept {
    return data_;
}

template <typename T>
const T* SafeVector<T>::end() const noexcept {
    return data_ + size_;
}

template <typename T>
size_t SafeVector<T>::size() const {
    return size_;
}

template <typename T>
bool SafeVector<T>::empty() const {
    return size_ == 0;
}