#include<iostream>
#include<memory>
#include "Header_Pointer/Var.h"
#include "Header_Pointer/Func.h"
#include "Header_Pointer/SmartPointer.h"


int main()
{
    std::cout << GetValue() << "\n";
    ShowData(GetDataFromCustomer);
    std::string (*Data)() = GetDataFromBD;
    ShowData(Data);
    MakePointer();
}
