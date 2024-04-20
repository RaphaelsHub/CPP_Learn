#pragma once

#include <assert.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct node
{
    string data;
    node* left{nullptr};
    node* right{nullptr};
};

template <typename T>
class binary_try
{
private:
    node* root = nullptr;

public:
    binary_try(const T a[], const size_t count) { init(a, count); }
    binary_try() { }

    void init(const T a[], size_t count)
    {
        if (!root)
            root = new node{a[0], nullptr, nullptr};

        for (size_t i = 1; i < count; ++i)
        {
            node* current = root;

            while (true)
            {
                if (a[i] > current->data)
                {
                    if (current->right == nullptr)
                    {
                        current->right = new node{a[i], nullptr, nullptr};
                        break;
                    }
                    else
                        current = current->right;
                }

                else
                {
                    if (current->left == nullptr)
                    {
                        current->left = new node{a[i], nullptr, nullptr};
                        break;
                    }
                    else
                        current = current->left;
                }
            }
        }
    }

    void add(const T tmp)
    {
        if (!root)
        {
            root = new node{tmp, nullptr, nullptr};
            return;  
        } 
    }
    
    void print()
    {
        if (root == nullptr)
            return;

        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
    
    void copyToArray(T tmp[], size_t i = 0)
    {
        if (root == nullptr)
            return;
        
        root = root->left;
        copyToArray(tmp, i);
        
        tmp[i++] = root->data;

        root = root->right;
        copyToArray(tmp, i);
    }

    node* find(const T& tmp)
    {
        while (root != nullptr && root->data != tmp)
            (root->data > tmp) ? root = root->left : root = root->right;
        return root;
    }

    size_t height()
    {
        if (root == nullptr)
            return 0;

        size_t leftCountHeads = height(root->left);
        size_t rightCountHeads = height(root->right);

        return (leftCountHeads > rightCountHeads) ? ++leftCountHeads : ++rightCountHeads;
    }

    void clear()
    {
        if (root == nullptr)
            return;

        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
};
