#pragma once

#include <iterator>

#define MY_DATA template <typename T>

MY_DATA
class IteratorArr
{
protected:
    T* data;
    using pointer = T*;
    using reference = T&;

public:
    //Constructors
    IteratorArr() : data(nullptr)
    {
    }
    IteratorArr(const pointer ptr) : data(ptr)
    {
    }
    IteratorArr(reference ref) : data(ref)
    {
    }

    //Destructors
    ~IteratorArr() = default;

    //Operators
    IteratorArr<T>& operator++()
    {
        ++data;
        return *this;
    }

    IteratorArr<T> operator++(T)
    {
        IteratorArr tmp = *this;
        ++data;
        return tmp;
    }

    IteratorArr<T>& operator--()
    {
        --data;
        return *this;
    }

    IteratorArr<T> operator--(T)
    {
        IteratorArr tmp = *this;
        ++data;
        return tmp;
    }

    reference operator->() { return *data; }
    pointer operator*() { return data; }

    friend bool operator==(const IteratorArr& a, const IteratorArr& b) { return a.data == b.data; }
    friend bool operator!=(const IteratorArr& a, const IteratorArr& b) { return !(a == b); }
};

MY_DATA
class rIteratorArr : public IteratorArr<T>
{
public:
    rIteratorArr(): IteratorArr<T>::data(nullptr)
    {
    }
    rIteratorArr(const T* ptr) : IteratorArr<T>::data(const_cast<T*>(ptr))
    {
    }

    rIteratorArr<T> operator++()
    {
        IteratorArr<T>::data = this->data++;
        return *this;
    }
    rIteratorArr<T> &operator++(T)
    {
        rIterator tmp = *this;
        IteratorArr<T>::data = this->data++;
        return tmp;
    }
};

MY_DATA
class Array
{
private:
    using Iter = IteratorArr<T>;
    using rIter = rIterator<T>;

    T* arr = nullptr;
    size_t count = 0;
    size_t cap = 0;

public:
    // Constructors
    Array() = default;

    Array(size_t initialSize) : count(initialSize), cap(initialSize)
    {
        arr = new T[cap];
    }

    Array(const Array& other) : count(other.count), cap(other.cap)
    {
        arr = new T[cap];
        std::copy(other.arr, other.arr + count, arr);
    }

    Array(Array&& other) noexcept : arr(other.arr), count(other.count), cap(other.cap)
    {
        other.arr = nullptr;
        other.count = other.cap = 0;
    }

    Array(std::initializer_list<T> initList) : count(initList.size()), cap(initList.size())
    {
        arr = new T[cap];
        std::copy(initList.begin(), initList.end(), arr);
    }

    // Destructor
    ~Array()
    {
        delete[] arr;
    }

    // Calling Iterators
    Iter begin() const { return Iter(arr); }
    Iter end() const { return Iter(arr + count); }
    rIter rbegin() const { return rIter(arr + count - 1); }
    rIter rend() const { return rIter(arr - 1); }

    // Implementation Methods
    size_t size() const { return count; }
    bool empty() const { return count == 0; }
    size_t capacity() const { return cap; }
    void clear()
    {
        delete[] arr;
        arr = nullptr;
        count = cap = 0;
    }
    T& operator[](size_t index)
    {
        if (index >= count)
            return arr[count-1];
        if(index<0)
            return arr[0];
        return arr[index];
    }
    const T& operator[](size_t index) const
    {
        if (index >= count)
            return arr[count - 1];
        if (index < 0)
            return arr[0];
        return arr[index]; // Возвращаем const T&
    }

    void insert(size_t index, const T& value)
    {
        if (index > count || index < 0)
            return;
        
        arr[index] = value;
        ++count;
    }
};
