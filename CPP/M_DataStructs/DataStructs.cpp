#include<iostream>
#include "Structs/1.StaticArray.h"
#include "Structs/2.Vector.h"
#include "Structs/3.ForwardList.h"
#include "Structs/4.ListBI.h"
#include "Structs/5.Queue.h"
#include "Structs/6.Stack.h"
#include "Structs/7.Deque.h"
#include "Structs/8.PriorityQueue.h"
#include "Structs/9.HashTable.h"
#include "Structs/10.BinaryTry.h"
#include "Structs/11.Set.h"
#include "Structs/12.Map.h"
#include "Structs/13.AVL.h"
#include "Structs/14.RBT.h"

int main(int argc, char* argv[])
{
    Array<int> array = {1, 2, 3, 4, 5};
    Vector<int> vector = {1, 2, 3, 4, 5};
    Queue<int> queue = {1, 2, 3, 4, 5};
    ListBI<int> list = {1, 2, 3, 4, 5};
    Stack<int> stack = {1,2,3,4,5};
    ForwardList<int> forward_list = {1 ,2 ,3 ,4, 5};
    Deque<int> deque = {1,2,3,4,5};
    HashTable<std::string, int> table;
    table.insert("apple", 5);
    binary_try<int>();
    std::vector<int> Date = {16, 54, 33, 34, 17, 19, 90, 2, 44, 32};
    PriorityQueue Heap(Date);
    Map<int, int> a;
    a.insert(1,4);
    Set<int> b;
    b.add(1);
    AVLTree<int>avl ;
    RBT<int>rbt;
    return 0;
}
