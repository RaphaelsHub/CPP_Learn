#include "MathFunc.h"
#include "Resources.h"

constexpr int globalVar = 10;

void PrintNums()
{
    constexpr int localVar = 10;
    extern int min, max;
    cout<<"Local var is equal: "<<localVar<<'\n';
    cout<<"Global var is equal: "<<globalVar<<'\n';
    cout<<"Global Extended max var is equal: "<<max<<'\n';
    cout<<"Global Extended min var is equal: "<<min<<'\n';
}

void MathExp()
{
    auto z = 0;

    z += 1;
    z *= 1;
    z /= 1;
    z -= 1;
    z++;
    z--;

    cout << "Z is equal: " << z << '\n';
}

void DevideNums()
{
    constexpr int a = 10;
    constexpr int b = 3;
    constexpr float c = b;
    cout << "a/b=" << a / b << "\n";
    cout << "a/b=" << static_cast<float>(a) / b << "\n";
    cout << "a/b=" << a / c << "\n";
}

void IncrementWith10()
{
    static int a = 15;
    a += 10;
}

void MagicNum()
{
    std::cout << "The random num is: " << rand() % 3 << '\n';
    // [b-a+1]+a - формула для того, чтобы задать диапозон чисел [a; b]
}

void LogicalOperations()
{
    // constexpr - a key word, that says to compile all these stuff can be done in a time of compiling
    constexpr int a = 100;
    constexpr int b = 33;
    constexpr int c = 22;
    constexpr int odd_nums = (a % 2) + (b % 2) + (c % 2);
    constexpr int even_nums = 3 - ((a % 2) + (b % 2) + (c % 2));
    constexpr int positive_nums = (a > 0) + (b > 0) + (c > 0);
    constexpr int negative_nums = (a < 0) + (b < 0) + (c < 0);

    std::cout << "The amount of odd numbers is equal " << odd_nums << '\n';
    std::cout << "The amount of even numbers is equal " << even_nums << '\n';
    std::cout << "The amount of positive numbers is equal " << positive_nums << '\n';
    std::cout << "The amount of negative numbers is equal " << negative_nums << '\n';
}

void TestMathFunc()
{
    std::cout << "The module of (-10) is equal = " << std::abs(-10) << '\n';
    std::cout << "The module of (-10.0) is equal " << std::fabs(-10.0) << '\n';
    std::cout << "The sqrt of 100 is equal " << std::sqrt(100) << '\n';
    std::cout << "The cbrt of 1000 is equal " << std::cbrt(1000) << '\n';
    std::cout << "The log of 2 grades is equal " << std::log(2) << '\n';
    std::cout << "The 2 into 3 is equal " << std::pow(2, 3) << '\n';
}