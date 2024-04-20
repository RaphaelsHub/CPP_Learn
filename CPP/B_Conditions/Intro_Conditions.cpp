#include<iostream>
#include <stdexcept>

using namespace std;

void ConditionalOperator()
{
    int a, b;
    std::cout<<"Enter an int num for a: ";
    std:: cin >> a;
    std::cout<<"Enter an int num for b: ";
    std:: cin >> b;
    
    if (a > b)
        std::cout << "A is bigger than B" << '\n';
    else
        std::cout << "B is bigger than A" << '\n';

    constexpr int g = 15;
    constexpr int h = 12;
    int max = g;
    
    // Второй вариант для нахождения большего числа
    if (g < h)
        max = h;
    std::cout << "Max num is " << max << '\n';
}

void ConditionalOperatorSwitch()
{
    char inChar;

    std::cout << "Press 1 if you are happy!" << '\n';
    std::cout << "Press 2 if you are unhappy!" << '\n';
    std::cout << "Press 3 if you are sad!" << '\n';
    std::cout << "Press 4 if you feel frustrated!" << '\n';
    std::cout << "Press 5 if you have no what to say!" << '\n';
    std::cout << "Write a number of the menu: ";

    std::cin >> inChar;

    switch (inChar)
    {
    case '1':
        std::cout << "I'm glad that you're happy)" << '\n';
        break;
    case '2':
        std::cout << "I'm sad that you're unhappy(" << '\n';
        break;
    case '3':
        std::cout << "It's a pity that you're sad(" << '\n';
        break;
    case '4':
        std::cout << "May I help you?" << '\n';
        break;
    case '5':
        std::cout << "I'm sorry for bothering you" << '\n';
        break;
    default:
        std::cout << "You have written something wrong" << '\n';
    }
}

void ConditionalOperatorElseIf()
{
    constexpr int a = 12;

    if (a > 11)
        std::cout << "A is bigger than 11" << '\n';
    if (a == 12)
        std::cout << "A is equal 12" << '\n';
    else
        std::cout << "No big deal" << '\n';

    // Если условие if неверно, тогда идет подпроверка else if. Если же else верно, тогда последующие условия не проверяются
    if (a > 12)
        std::cout << "A is less than 12" << '\n';
    else if (a == 11)
        std::cout << "A is equal 11" << '\n';
    else if (a > 11)
        std::cout << "A is bigger than 11" << '\n';
    else
        std::cout << "No big deal" << '\n';

    if (a == 11)
        std::cout << "A is equal 11" << '\n';
    else if (a > 11)
    {
        std::cout << "Hey, A is bigger than 11" << '\n';

        if (a > 12)
            std::cout << "A is bigger than 12" << '\n';
        else if (a == 12)
            std::cout << "Is equal 12" << '\n';
    }
}

void ConditionalOperatorOrAnd()
{
    constexpr int a = 18;
    constexpr int b = 98;
    
    if (18 <= a && b <= 98)
        std::cout << "It is true" << '\n';
    else
        std::cout << "It is false" << '\n';

    constexpr int s = 18;
    constexpr int q = 98;
    
    if (s >= 18 || q < 98)
        std::cout << "It is true" << '\n';
    else
        std::cout << "It is false" << '\n';
}

void TernarOperator()
{
    constexpr int i = -10;
    constexpr int squareOfTheNum = i > 0 ? i * i : -(i * i);
    std::cout << "The square of " << i << " is equal " << squareOfTheNum << '\n';

    constexpr int x = 10;
    constexpr int y = 10;
    x == y ? (std::cout << "It's equal\n") : std::cout << "It's not equal\n";
}

void TryCatch()
{
    try
    {
        constexpr int y = 0;

        if (y == 0)
            throw std::runtime_error("Is equal 0!");

        std::cout << "All right!" << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error command: " << e.what() << "\n";
    }
}

int main()
{
    ConditionalOperatorSwitch();
    ConditionalOperatorElseIf();
    ConditionalOperatorOrAnd();
    TernarOperator();
    TryCatch();
    return 0;
}
