#pragma once
#include <string>

//Functions
inline std::string GetDataFromBD() { return "BD"; }
inline std::string GetDataFromCEO() { return "CEO"; }
inline std::string GetDataFromCustomer() { return "CUSTOMER"; }

//Pointer to function
inline void ShowData(std::string (*Data)())
{
    std::cout << Data() << "\n";
}
