#ifndef SAFEVECTOR_H
#define SAFEVECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class SafeVector {
public:
    SafeVector();
    ~SafeVector();

    SafeVector(const SafeVector&);
    SafeVector& operator=(SafeVector other);
    void push_back(const T& value);

    T& at(size_t index);
    const T& at(size_t index) const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void swap(SafeVector& other);
    size_t size() const;

private:
    T* data_;
    size_t size_;
    size_t capacity_;
    void reallocate(size_t new_capacity);
};

#endif