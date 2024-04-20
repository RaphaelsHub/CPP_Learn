#pragma once
/**
 * \brief
* Красно-черное дерево (RBT):
Цвета узлов:
Каждый узел красно-черного дерева имеет ассоциированный цвет: либо красный, либо черный.
Основное свойство красно-черного дерева: нет двух красных узлов подряд; каждый путь от корня до листа содержит одинаковое количество черных узлов.
Операции:
Вставка, удаление и поиск элемента в красно-черном дереве также выполняются за время, пропорциональное логарифму количества узлов в дереве.
это два типа самобалансирующихся двоичных деревьев поиска, которые используются для эффективного выполнения операций вставки, удаления и поиска элементов. Оба типа деревьев гарантируют логарифмическое время выполнения этих операций, что делает их очень эффективными структурами данных.
 */
#include <iostream>

enum Color { RED, BLACK };

template<typename T>
class RBTNode {
public:
    T data;
    RBTNode<T>* left;
    RBTNode<T>* right;
    RBTNode<T>* parent;
    Color color;

    RBTNode(const T& value, Color nodeColor = RED, RBTNode<T>* parentNode = nullptr)
        : data(value), left(nullptr), right(nullptr), parent(parentNode), color(nodeColor) {}
};

template<typename T>
class RBT {
private:
    RBTNode<T>* root;

    void rotateLeft(RBTNode<T>* x) {
        RBTNode<T>* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(RBTNode<T>* y) {
        RBTNode<T>* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixInsertion(RBTNode<T>* newNode) {
        while (newNode != root && newNode->parent->color == RED) {
            if (newNode->parent == newNode->parent->parent->left) {
                RBTNode<T>* uncle = newNode->parent->parent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode->parent->parent->color = RED;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        rotateLeft(newNode);
                    }
                    newNode->parent->color = BLACK;
                    newNode->parent->parent->color = RED;
                    rotateRight(newNode->parent->parent);
                }
            } else {
                RBTNode<T>* uncle = newNode->parent->parent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode->parent->parent->color = RED;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rotateRight(newNode);
                    }
                    newNode->parent->color = BLACK;
                    newNode->parent->parent->color = RED;
                    rotateLeft(newNode->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void inorderTraversal(RBTNode<T>* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    RBT() : root(nullptr) {}

    void insert(const T& value) {
        RBTNode<T>* newNode = new RBTNode<T>(value);
        RBTNode<T>* current = root;
        RBTNode<T>* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                delete newNode;
                return; // Узел уже существует в дереве
            }
        }

        newNode->parent = parent;

        if (parent == nullptr) {
            root = newNode;
        } else if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixInsertion(newNode);
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }
};
