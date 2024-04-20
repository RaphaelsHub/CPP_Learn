#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

class PriorityQueue
{
public:
    PriorityQueue(std::vector<int>& Date)
    {
        Copy = Date;
        count = Date.size() - 1;
        countSoartedElem = count;
        Heapify();
    }

    void Print()
    {
        for (int i = 0; i <= count; i++)
            std::cout << Copy[i] << " ";
        std::cout << "\n";
    }

    void Heapify()
    {
        int i = !(count % 2) ? count / 2 - 1 : count / 2;
        int max = 0;
        for (; i >= 0; i--)
        {
            max = GetMaxIndex(Left(i), Right(i), count);
            if (Copy[max] > Copy[i])
            {
                std::swap(Copy[i], Copy[max]);
                SiftDown(max, count);
            }
        }
    }

    int ExtractMax()
    {
        int numToPop = Copy[0];
        Copy.erase(Copy.begin());
        count = Copy.size() - 1;
        countSoartedElem = count;
        return numToPop;
    }

    void InsertKey(int a)
    {
        Copy.insert(Copy.begin(), a);
        count = Copy.size() - 1;
        countSoartedElem = count;
        SiftDown(0, count);
    }

    void HeapSort()
    {
        for (int i = count; i > 0; i--)
        {
            std::swap(Copy[0], Copy[i]);
            countSoartedElem--;
            SiftDown(0, countSoartedElem);
            Print();
        }
    }

private:
    int count, countSoartedElem, max;
    std::vector<int> Copy;

    int Left(int parent)
    {
        return parent * 2 + 1;
    }

    int Right(int parent)
    {
        return parent * 2 + 2;
    }

    int GetMaxIndex(int left, int right, int arrCount)
    {
        if (right <= arrCount)
        {
            int m = Copy[left] > Copy[right] ? left : right;
            if (Copy[m] > Copy[left / 2])

                return Copy[left] > Copy[right] ? left : right;
        }
        return Copy[left / 2] < Copy[left] ? left : left / 2;
    }

    void SiftDown(int i, int lenght)
    {
        int index = i;
        while (Left(index) <= lenght || Right(index) <= lenght)
        {
            max = GetMaxIndex(Left(index), Right(index), lenght);
            if (max == index)
                return;
            std::swap(Copy[index], Copy[max]);

            index = max;
        }
    }
};
