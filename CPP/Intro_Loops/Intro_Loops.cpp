#include<iostream>

using namespace std;

void func1()
{
    char b = '\0';
    for (;;)
    {
        constexpr char a = 'A';
        cout<<"Enter a char: ";
        cin >> b;
        if (a == b)
            break;
    }
}

void func2()
{
    int x, y;
    for (x = 100, y = 1; x != 10 && y < 19; x -= 5, y++)
        std::cout << "The " << y << " num is " << x << ", it's square is " << x * x << '\n';
}

void func4()
{
    while (true)
    {
        static int x = 10;
        if(x==3)
            break;
        x--;
    }
}

void func3()
{
    int z=1;
    while (z<=10)
        z++;
}

void func5()
{
    int suma=0, a=265;
    int sum = a / 100 + a / 10 % 10 + a % 10; // 13

    while (a > 0)
    {
        suma += a % 10;
        a /= 10;
    }
}

void func6()
{
    int y=10;
    if (y==10)
        goto metka;
    metka:
        y--;
}

void func7()
{
    char* stringg = new char[10];
    cin>>stringg;
}

void func8()
{
    int ch; 
    
    std::cout << "Press 1 to work\n";
    std::cout << "Press 2 to save\n";
    std::cout << "Press 3 to clear\n";
    std::cout << "Press 4 to exit\n";

    do {
        std::cout << "\tChoose an option: ";
        std::cin >> ch; 

        switch (ch) {
        case 1:
            std::cout << "You want to work" << '\n';
            break;
        case 2:
            std::cout << "You want to save" << '\n';
            break;
        case 3:
            std::cout << "You want to clear" << '\n';
            break;
        case 4:
            std::cout << "You want to exit" << '\n';
            return;
        default:
            std::cout << "Invalid option. Please choose again." << '\n';
        }
    } while (ch > 4 || ch < 1);
}

void func9()
{
    int b=0;
    do
    {
        cin>>b;    
    }
    while (b!=3);
}

int main()
{
    func1();
    func2();
    func3();
    func4();
    func5();
    func6();
    func7();
    func8();
    func9();
    return 0;
}
