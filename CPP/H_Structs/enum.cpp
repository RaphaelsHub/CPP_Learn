#include "enum.h"

#include <iostream>

void CheckForStatus(valute status)
{
    switch(status) 
    {
    case euro: std::cout << "euro";
        break;
    case dollor: std::cout<<R"(dollar)";
        break;
    case leuRoman: std::cout<<"leu roman";
        break;
    }
}
