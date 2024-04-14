#include<iostream>
#include <vector>

#include "MarkConstChangibleVars.h"
#include "NameSpace.h"
#include "SetOfVarsProtection.h"
#include "friends.h"
#include"Polimorf.h"
#include "Sample.h"
#include"Functors.h"
#include"Predicats.h"
#include"Template.h"

int main()
{
    typedef std::vector<int> codes;
    codes Alex = {1,2,3,4,5};
    
    OpenNameSpace();
    SetOfTheProtection();
    ShowMagic();
    CheckFriends() ;
    Polimorphism();
    CallInfo();
    CallWithTemp();
    ShowFuct();
    ShowPred();
}
