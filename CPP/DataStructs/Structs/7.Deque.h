#pragma once

#include "15.IteratrorRiterator.h"
#include "4.ListBI.h"

template <typename T, typename container = ListBI<T>>
class Deque {
private:
    using Iter = Iterator<T>;
    using rIter = rIterator<T>;

    container list; // Объект списка внутри класса Deque

public:
    // Constructors
    Deque() : list() {}

    Deque(const T a[], size_t size) : list(a, size) {}

    Deque(size_t size) : list(size) {}

    Deque(const Deque& b) : list(b.list) {}

    Deque(Iter begin, Iter end) : list(begin, end) {}

    Deque(rIter rbegin, rIter rend) : list(rbegin, rend) {}

    Deque(std::initializer_list<T> a) : list(a) {}

    Deque(const T a[]) : list(a, strlen(a) + 1) {}

    // Destructor
    ~Deque() { list.Clear(); }

    // Iterator calling
    Iter begin() const { return list.begin(); }

    Iter end() const { return list.end(); }

    rIter rbegin() const { return list.rbegin(); }

    rIter rend() const { return list.rend(); }

    // Deque Functions
    void PushFront(const T& a) { list.Push_front(a); }

    void PushBack(const T& a) { list.Push_back(a); }

    T PopFront() { return list.Pop_front(); }

    T PopBack() { return list.Pop_back(); }

    T& Front() { return list.Front(); }

    T& Back() { return list.Back(); }

    const T& Front() const { return list.Front(); }

    const T& Back() const { return list.Back(); }

    bool Empty() const { return list.Empty(); }

    size_t Size() const { return list.Length(); }

    void Clear() { list.Clear(); }

    void Swap(Deque<T>& a) { list.Swap(a.list); }
};
