#pragma once
/*Дерево AVL:
типа самобалансирующихся двоичных деревьев поиска, которые используются для эффективного выполнения операций вставки, удаления и поиска элементов. Оба типа деревьев гарантируют логарифмическое время выполнения этих операций, что делает их очень эффективными структурами данных.
Сбалансированность:
В AVL-дереве для каждой вершины высоты левого и правого поддеревьев различаются не более чем на один (высота поддерева - это количество узлов на пути от данного узла до самого удаленного листа).
При вставке и удалении узлов AVL-дерево может потребовать выполнения операций балансировки, таких как повороты (rotation), чтобы сохранить эту балансировку.
Операции:
Вставка, удаление и поиск элемента в AVL-дереве выполняются за время, пропорциональное логарифму количества узлов в дереве.
  */
#include <iostream>
#include <algorithm>

template<typename T>
class AVLNode {
public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;

    AVLNode(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

template<typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    int height(AVLNode<T>* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode<T>* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode<T>* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode<T>* balance(AVLNode<T>* node) {
        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1) {
            if (balanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (balance < -1) {
            if (balanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode<T>* insert(AVLNode<T>* node, const T& value) {
        if (node == nullptr) {
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        return balance(node);
    }

    void inorderTraversal(AVLNode<T>* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }
};
