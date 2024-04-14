#pragma once
#include <iostream>

class Demo
{
private:
    mutable int i = 0;
public:
    int Get_I() const { return i; }
    void Set_I(int x) const { i = x; } //Не смотря на то, что метод запрещает изменение, спецификатор mutable дает возможность зименять особые параметры
};

void ShowMagic()
{
    Demo a;
    a.Set_I(10);
    std::cout << a.Get_I()<<"\n";
}