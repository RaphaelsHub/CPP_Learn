#pragma once

#include<iostream>

using namespace std;

enum Color
{
    green,
    red,
    yellow
};

class gig
{
private:
    int countRedApples = 0;
    int countGreenApples = 0;

public:
    gig() = default;
    ~gig() = default;

    void operator()(Color color)
    {
        if (color == green)
            countGreenApples++;
        else
            countRedApples++;

        cout << "GreenApples = " << countGreenApples << " RedApples = " << countRedApples << endl;
    }
};

void ShowFuct()
{
    gig A;
    Color array[] = {red, green, green, green, green, red};

    for (auto elem : array)
        A(elem);
}
