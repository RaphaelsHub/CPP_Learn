
void buble_sort(int* arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int x = i+1; x < 10; x++)
        {
            if(arr[i]>arr[x])
            {
                const int tmp = arr[x];
                arr[x]=arr[i];
                arr[i]=tmp;
            }
        }
    }
}

void InsertionSort(int* arr)
{
    for (int i=1;i<10;i++)
    {
        const int key = arr[i];
        int ind=0;
        for (int x=i-1;i>=0 && arr[x]>key; i--)
        {
            if(arr[x]>arr[i])
            {
                arr[i]=arr[x];
            }
            ind=x;
        }
        arr[ind]=key;
    }
}

void MinSort(int* arr)
{
    for (int i = 0; i < 10-1; i++)
    {
        int min_index=i;
        for (int x = min_index+1; x < 10; x++)
        {
            if(arr[x]<arr[min_index])
            {
                min_index = x;
            }
        }

        const int tmp = arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=tmp;

    }
}

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
    buble_sort(nums);
    InsertionSort(nums);
    MinSort(nums);
    BinarySearch(nums);
}
