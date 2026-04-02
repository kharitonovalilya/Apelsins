#pragma once
#include <stdexcept>

template <typename T>
class SafeVector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    SafeVector();
    explicit SafeVector(size_t count);
    SafeVector(const SafeVector& other);
    ~SafeVector();

    SafeVector& operator=(const SafeVector& other);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T& at(size_t index);
    const T& at(size_t index) const;

    void push_back(const T& value);
    void reserve(size_t new_capacity);

    T* begin() noexcept;
    T* end() noexcept;
    const T* begin() const noexcept;
    const T* end() const noexcept;

    size_t size() const;
    bool empty() const;
};

#include "../src/safe_vector.cpp" 