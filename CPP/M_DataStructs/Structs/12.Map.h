#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
/*
*Этот класс Map реализует основные операции работы с ассоциативным массивом: добавление элемента (insert), доступ к значению по ключу (at), проверка наличия ключа в map (contains), удаление элемента по ключу (erase) и получение размера map (size). Класс Map использует внутренний контейнер std::vector<std::pair<K, V>>, где каждая пара представляет собой "ключ-значение".

Этот пример реализует простейшую версию map. Обратите внимание, что эта реализация имеет линейную временную сложность для большинства операций (например, поиск, вставка, удаление), что может быть неэффективно для больших наборов данных. В реальном коде рекомендуется использовать стандартные реализации ассоциативных массивов из стандартной библиотеки C++ (например, std::unordered_map или std::map).
 */
template <typename K, typename V>
class Map
{
private:
    std::vector<std::pair<K, V>> elements;

public:
    // Добавление элемента с ключом key и значением value
    void insert(const K& key, const V& value)
    {
        for (auto& pair : elements)
        {
            if (pair.first == key)
            {
                throw std::invalid_argument("Key already exists.");
            }
        }
        elements.push_back(std::make_pair(key, value));
    }

    // Получение значения по ключу key
    V& at(const K& key)
    {
        for (auto& pair : elements)
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found.");
    }

    // Проверка наличия ключа в map
    bool contains(const K& key) const
    {
        for (const auto& pair : elements)
        {
            if (pair.first == key)
            {
                return true;
            }
        }
        return false;
    }

    // Удаление элемента по ключу key
    void erase(const K& key)
    {
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (it->first == key)
            {
                elements.erase(it);
                return;
            }
        }
    }

    // Получение размера map
    size_t size() const
    {
        return elements.size();
    }
};
