#pragma once
#include <iostream>

class Fruit
{
protected:
    int posX=10;
    int posY=10;
public:
    Fruit()=default;
    ~Fruit()=default;
};

class Apple:private Fruit
{
public:
    Apple()=default;
    ~Apple()=default;
    
    void ShowVars() const
    {
        std::cout << posX<<" ";
        std::cout << posY<<"\n";
    }
};

inline void SetOfTheProtection()
{
    Apple a;
    a.ShowVars();
}
