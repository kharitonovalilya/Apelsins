#pragma once
#include <stdexcept>

template <typename T> class SafeVector {
private:
  T *data_;
  size_t size_;
  size_t capacity_;

public:
  SafeVector() : data_(nullptr), size_(0), capacity_(0) {}

  explicit SafeVector(size_t count) : size_(count), capacity_(count) {
    data_ = new T[count];
  }

  SafeVector(const SafeVector &other)
      : size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  ~SafeVector() { delete[] data_; }

  SafeVector &operator=(const SafeVector &other) {
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

  T &operator[](size_t index) { return data_[index]; }

  const T &operator[](size_t index) const { return data_[index]; }

  T &at(size_t index) {
    if (index >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }

  const T &at(size_t index) const {
    if (index >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }

  void push_back(const T &value) {
    if (size_ >= capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
  }

  void reserve(size_t new_capacity) {
    if (new_capacity <= capacity_)
      return;

    T *new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

  T *begin() noexcept { return data_; }
  T *end() noexcept { return data_ + size_; }

  const T *begin() const noexcept { return data_; }
  const T *end() const noexcept { return data_ + size_; }

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }
};