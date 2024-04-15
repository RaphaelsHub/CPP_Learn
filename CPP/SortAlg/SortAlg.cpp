#include "SortingAlgorithms/3.BoobleSort.h"
#include "SortingAlgorithms/4.InsertionSort.h"
#include "SortingAlgorithms/5.SelectionSort.h"




void BinarySearch(const int* arr)
{
    constexpr int up=0;
    constexpr int down=9;
    int middle=(up+down)/2+up;
    while(up<=down)
    {
        constexpr int num=3;
        if(arr[middle]==num)
            break;
        num<arr[middle]?middle--:middle++;
    }
}


int main()
{
    int nums[10] = {2,6,8,2,3,5,7,8,5,2};
    BubleSort(nums,10);
    int nums1[10] = {2,6,8,2,3,5,7,8,5,2};
    InsertionSort(nums1, 10);
    int nums2[10] = {2,6,8,2,3,5,7,8,5,2};
    MinSort(nums2);
}
