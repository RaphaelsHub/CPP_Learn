#pragma once

#include "ListBI.h"
#include "IteratrorRiterator.h"

template <typename T, typename container = ListBI<T>>
class Stack {
private:
    using Iter = Iterator<T>;
    using rIter = rIterator<T>;

    container list; // Объект списка внутри класса Stack

public:
    // Constructors
    Stack() : list() {}
    Stack(const T a[], size_t size) : list(a, size) {}
    Stack(size_t size) : list(size) {}
    Stack(const Stack &b) : list(b.list) {}
    Stack(Iter begin, Iter end) : list(begin, end) {}
    Stack(rIter rbegin, rIter rend) : list(rbegin, rend) {}
    Stack(std::initializer_list<T> a) : list(a) {}
    Stack(const T a[]) : list(a, strlen(a) + 1) {}

    // Destructor
    ~Stack() { list.Clear(); }

    // Iterator calling
    Iter begin() const { return list.begin(); }
    Iter end() const { return list.end(); }
    rIter rbegin() const { return list.rbegin(); }
    rIter rend() const { return list.rend(); }

    // Stack Functions
    void push(const T &a) { list.Push_back(a); }
    T pop() { return list.Pop_back(); }
    T &top() { return list.Back(); }
    const T &top() const { return list.Back(); }
    bool empty() const { return list.Empty(); }
    size_t size() const { return list.Length(); }
    void clear() { list.Clear(); }
    void swap(Stack<T> &a) noexcept { list.Swap(a.list); }
};
