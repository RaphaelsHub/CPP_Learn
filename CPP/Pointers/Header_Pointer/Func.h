#pragma once
#include <string>

//Functions
std::string GetDataFromBD() { return "BD"; }
std::string GetDataFromCEO() { return "CEO"; }
std::string GetDataFromCustomer() { return "CUSTOMER"; }

//Pointer to function
void ShowData(std::string (*Data)())
{
    std::cout << Data() << "\n";
}
