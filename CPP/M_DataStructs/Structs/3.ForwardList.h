#pragma once

#include "15.IteratrorRiterator.h"
#include "4.ListBI.h"

template<typename T,typename container = ListBI<T>>
class ForwardList
{
private:
    using Iter = Iterator<T>;
    using rIter = rIterator<T>;

    container list; // Объект списка внутри класса Queue
public:
    // Constructors
    ForwardList() : list(){}
    ForwardList(const T a[], size_t size) : list(a, size){}
    ForwardList(size_t size) : list(size){}
    ForwardList(const ForwardList& b) : list(b.list){}
    ForwardList(Iter begin, Iter end) : list(begin, end){}
    ForwardList(rIter rbegin, rIter rend) : list(rbegin, rend){}
    ForwardList(std::initializer_list<T> a) : list(a){}
    ForwardList(const T a[]) : list(a, strlen(a) + 1){}
    
    // Destructor
    ~ForwardList() { list.Clear(); }

    // Iterator calling
    Iter begin() const { return list.begin(); }
    Iter end() const { return list.end(); }
    rIter rbegin() const { return list.rbegin(); }
    rIter rend() const { return list.rend(); }

    // Queue Functions
    void PushBack(const T& a) { list.Push_back(a); }
    T PopBack() { return list.Pop_front(); }
    T& Front() { return list.Front(); }
    T& Back() { return list.Back(); }
    const T& Front() const { return list.Front(); }
    const T& Back() const { return list.Back(); }
    bool Empty() const { return list.Empty(); }
    size_t Count() const { return list.Length(); }
    void Clear() { list.Clear(); }
    void Swap(ForwardList<T>& a) { list.Swap(a.list); }
};
