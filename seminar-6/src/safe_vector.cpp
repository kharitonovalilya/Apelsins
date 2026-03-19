#include "safe_vector.h"

template <typename T>
SafeVector<T>::SafeVector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
SafeVector<T>::~SafeVector() {
  delete[] data_;
}

template <typename T>
void SafeVector<T>::push_back(const T& value) {
  if (size_ >= capacity_) {
    size_t new_capacity = 1;
    if (capasity_ != 0) {
      new_capacity = capacity_ * 2;
    }
    reallocate(new_capacity);
  }
  size_++;
  data_[size_] = value;
}

template <typename T>
void SafeVector<T>::reallocate(size_t new_capacity) {
  T* new_data = new T[new_capacity];
  for (size_t idx = 0; idx < size_; idx++) {
    new_data[idx] = data_[idx];
  }
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
T& SafeVector<T>::at(size_t index) {
  if (index >= size_) {
    throw std::out_of_range("SafeVector::at: index out of range");
  }
  return data_[index];
}

template <typename T>
const T& SafeVector<T>::at(size_t index) const {
  if (index >= size_) {
    throw std::out_of_range("SafeVector::at: index out of range");
  }
  return data_[index];
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
size_t SafeVector<T>::size() const {
  return size_;
}

template <typename T>
SafeVector<T>::SafeVector(const SafeVector& other)
    : data_(nullptr), size_(0), capacity_(0) {
  if (other.size_ > 0) {
    data_ = new T[other.capacity_];
    capacity_ = other.capacity_;
    for (size_t idx = 0; idx < other.size_; idx++) {
      data_[idx] = other.data_[idx];
    }
    size_ = other.size_;
  }
}

template <typename T>
SafeVector<T>& SafeVector<T>::operator=(SafeVector other) {
  swap(other);
  return *this;
}

template <typename T>
void SafeVector<T>::swap(SafeVector& other) {
  using std::swap;
  swap(data_, other.data_);
  swap(size_, other.size_);
  swap(capacity_, other.capacity_);
}