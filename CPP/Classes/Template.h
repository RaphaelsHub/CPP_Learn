#pragma once
using namespace std;

template <class AType, int size>
class atype
{
    AType a[size]; 
public:
    atype()
    {
        register int i;
        for (i = 0; i < size; i++)
            a[i] = i;
    }
};

void CallWithTemp()
{
    atype<int, 10> intob;        
    atype<double, 15> doubleob; 
}
