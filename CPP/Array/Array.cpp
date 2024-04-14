
void f1(int* arr);
void f2(int arr[]);
void f3(int arr[3]);
void f4(int (*arr)[2]);

void DiagonalsSum()
{
    const int n = 3;
    int a[n][n], Sum = 0, Summ = 0;

    for (int i=0;i<n;i++)
        for (int y=0;y<n;y++)
            a[i][y]=i*y;
    
    // сумма главной и побочной диагонали
    for (int i = 0; i < n; i++)
    {
        Sum += a[i][i];
        Summ += a[i][n - i - 1];
    }

    // сумма элементов выше главной диагонали
    Sum = 0;
    for (int i = 0; i < n; i++)
    {for (int j = i; j < n; j++)
        Sum+=a[i][j];}

    // сумма элементов выше побочной диагонали
    Sum = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j < n-i; j++)
            Sum+=a[i][j];}

    // сумма 1 четверти
    Sum = 0;
    for (int i = 0; i < n/2; i++){
        for (int j = i; j < n-i; j++)
            Sum+=a[i][j];}

    // сумма 2 четверти
    Sum = 0;
    for (int i = n-1,z=0; i >= n/2; i--,z++)
        for (int j = 0+z; j < n-z; j++)
            Sum+=a[j][i];

    // сумма 3 четверти
    Sum = 0;
    for (int i = n-1, z=0; i >= n/2; i--,z++)
        for (int j = 0+z; j<n-z; j++)
            Sum+=a[i][j];
          
    // сумма 4 четверти
    Sum = 0;
    for (int i = 0,z=0; i < n/2; i++,z++)
        for (int j = 0+z; j < n-z; j++)
            Sum+=a[j][i];
}

void PushToRight(int arr[3])
{
    int c = arr[2];
    for (int i=3-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=c;
}

void SortTwoArrays(int arr[3], int array[3])
{
    int i = 0, j = 0;
    int c[6];
    while (i < 3 && j < 3)
    {
        arr[i] >= array[j] ? c[i + j] = array[j++] : c[i + j] = arr[i++];
    }
    while (i < 3)
        c[i + j] = arr[i++];
    while (j < 3)
        c[i + j] = array[j++];
}


int main()
{
    int array[] = { 1, 2, 3 };
    int array1[2][2] = {{1, 2}, {3, 4}};

    //f1(array);
    //f2(array);
    //f3(array);
    //f4(array1);
    DiagonalsSum();
    PushToRight(array);
    SortTwoArrays(array,array);
    return 0;
}
