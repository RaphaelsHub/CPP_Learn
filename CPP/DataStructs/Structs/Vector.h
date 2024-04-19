#pragma once

#include <iostream>
#include <iterator>
#include <initializer_list>

template <typename T>
class VectorIterator;

template <typename T>
class VectorReverseIterator;

template <typename T>
class Vector {
private:
    T* arr = nullptr;
    size_t count = 0;
    size_t cap = 0;

public:
    using iterator = VectorIterator<T>;
    using reverse_iterator = VectorReverseIterator<T>;

    // Constructors
    Vector() = default;

    Vector(size_t initialSize) : count(initialSize), cap(initialSize) {
        arr = new T[cap];
    }

    Vector(const std::initializer_list<T>& initList) : count(initList.size()), cap(initList.size()) {
        arr = new T[cap];
        std::copy(initList.begin(), initList.end(), arr);
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    // Methods
    size_t size() const { return count; }

    bool empty() const { return count == 0; }

    void clear() {
        delete[] arr;
        arr = nullptr;
        count = cap = 0;
    }

    T& operator[](size_t index) {
        if (index >= count)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= count)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    void push_back(const T& value) {
        if (count >= cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            reserve(new_cap);
        }
        arr[count++] = value;
    }

    void pop_back() {
        if (count > 0) --count;
    }

    void reserve(size_t new_cap) {
        if (new_cap <= cap) return;
        T* new_arr = new T[new_cap];
        std::copy(arr, arr + count, new_arr);
        delete[] arr;
        arr = new_arr;
        cap = new_cap;
    }

    iterator begin() const {
        return iterator(arr);
    }

    iterator end() const {
        return iterator(arr + count);
    }

    reverse_iterator rbegin() const {
        return reverse_iterator(arr + count - 1);
    }

    reverse_iterator rend() const {
        return reverse_iterator(arr - 1);
    }
};

template <typename T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T* ptr;

public:
    VectorIterator(T* p) : ptr(p) {}

    VectorIterator& operator++() {
        ++ptr;
        return *this;
    }

    VectorIterator operator++(int) {
        VectorIterator tmp = *this;
        ++ptr;
        return tmp;
    }

    VectorIterator& operator--() {
        --ptr;
        return *this;
    }

    VectorIterator operator--(int) {
        VectorIterator tmp = *this;
        --ptr;
        return tmp;
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    bool operator==(const VectorIterator& other) const { return ptr == other.ptr; }

    bool operator!=(const VectorIterator& other) const { return !(*this == other); }
};

template <typename T>
class VectorReverseIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T* ptr;

public:
    VectorReverseIterator(T* p) : ptr(p) {}

    VectorReverseIterator& operator++() {
        --ptr;
        return *this;
    }

    VectorReverseIterator operator++(int) {
        VectorReverseIterator tmp = *this;
        --ptr;
        return tmp;
    }

    VectorReverseIterator& operator--() {
        ++ptr;
        return *this;
    }

    VectorReverseIterator operator--(int) {
        VectorReverseIterator tmp = *this;
        ++ptr;
        return tmp;
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    bool operator==(const VectorReverseIterator& other) const { return ptr == other.ptr; }

    bool operator!=(const VectorReverseIterator& other) const { return !(*this == other); }
};