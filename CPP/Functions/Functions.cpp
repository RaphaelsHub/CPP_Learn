#include "iostream"

int RecursionFibonaci(int a)
{
    if (a == 0 || a == 1)
        return 1;
    return RecursionFibonaci(a - 2) + RecursionFibonaci((a - 1));
}

int RecursionFactorial(int a)
{
    if (a == 1)
        return 1;
    const auto res = a * RecursionFibonaci(a - 1);
    return res;
}

int RecursionMutly(const int a, const int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    return a * (RecursionMutly(a, b - 1));
}

int RecursionNOD(const int a, const int b)
{
    if (b == 0) return a;
    return RecursionNOD(b, a % b);
}

inline int func(const int i, const int b)
{
    return i + b;
}

int main()
{
    constexpr int a = 4;
    constexpr int b = 3;
    RecursionFibonaci(a);
    RecursionFactorial(a);
    RecursionMutly(a, b);
    RecursionNOD(a, b);
    const int c = func(a, b);
    std::cout << c;
}
