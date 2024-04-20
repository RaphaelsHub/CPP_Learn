#pragma once

#include <vector>
#include <list>
#include <utility>
#include <iostream>

template<typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class HashTable {
private:
    using HashedValueType = std::pair<KeyType, ValueType>; 
    using Bucket = std::list<HashedValueType>;
    using Buckets = std::vector<Bucket>;

    size_t size;
    Buckets buckets;
    Hash hashFunction;

    size_t hash(const KeyType& key) const {
        return hashFunction(key) % buckets.size();
    }

public:
    explicit HashTable(size_t initialSize = 10, const Hash& hashFn = Hash())
        : size(0), buckets(initialSize), hashFunction(hashFn) {}

    void insert(const KeyType& key, const ValueType& value) {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                // Key already exists, updating value
                const_cast<ValueType&>(pair.second) = value;
                return;
            }
        }
        buckets[index].emplace_back(key, value);
        ++size;
    }
    bool find(const KeyType& key, ValueType& value) const {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }
    bool remove(const KeyType& key) {
        size_t index = hash(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --size;
                return true;
            }
        }
        return false;
    }
    size_t getSize() const { return size; }
    bool empty() const { return size == 0; }
};
