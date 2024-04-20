#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
*В контексте программирования и структур данных, "set" (множество) - это абстрактная структура данных, которая представляет собой коллекцию уникальных элементов без какого-либо определенного порядка. Она обладает рядом особенностей:

Уникальность элементов: Каждый элемент в множестве уникален, то есть он может встречаться в множестве только один раз.
Отсутствие порядка: Элементы в множестве не имеют определенного порядка. Это означает, что при добавлении элементов в множество итерация по элементам множества может происходить в произвольном порядке.
Множество обычно реализуется таким образом, чтобы операции добавления, удаления и поиска элементов в нем были эффективными. В разных языках программирования могут быть различные реализации множеств, такие как встроенные классы Set (например, в Python), структуры данных Set (например, в C++ STL), или реализации на основе хеш-таблиц или деревьев (например, HashSet и TreeSet в Java).

Структура данных множество обычно используется в ситуациях, когда нужно хранить набор уникальных элементов и быстро выполнять операции добавления, удаления и проверки наличия элементов. Например, множество может использоваться для хранения списка уникальных идентификаторов, фильтрации дубликатов из коллекции данных или проверки наличия элемента в наборе.
 */

template <typename T>
class Set {
private:
    std::vector<int> elements;

public:
    void add(T element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            elements.push_back(element);
        }
    }

    void remove(T element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    bool contains(T element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    int size() const {
        return elements.size();
    }

    Set union_set(const Set& other_set) const {
        Set new_set;
        for (int element : elements) {
            new_set.add(element);
        }
        for (int element : other_set.elements) {
            new_set.add(element);
        }
        return new_set;
    }

    Set intersection(const Set& other_set) const {
        Set new_set;
        for (int element : elements) {
            if (other_set.contains(element)) {
                new_set.add(element);
            }
        }
        return new_set;
    }

    Set difference(const Set& other_set) const {
        Set new_set;
        for (int element : elements) {
            if (!other_set.contains(element)) {
                new_set.add(element);
            }
        }
        return new_set;
    }

    bool is_subset(const Set& other_set) const {
        for (int element : elements) {
            if (!other_set.contains(element)) {
                return false;
            }
        }
        return true;
    }
};
