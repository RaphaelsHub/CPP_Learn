#include "OOP/Interface.h"
#include "OOP/Friend.h"
#include "OOP/Functors.h"
#include "OOP/InseartedClass.h"
#include "OOP/NameSpace.h"
#include "OOP/ConstMethod.h"
#include "OOP/Lib.h"
#include <vector>

int main()
{
    typedef std::vector<int> codes;
    codes Alex = {1,2,3,4,5};

    CheckInterface();
    CheckFriends();
    ShowMagic();
    OpenNameSpace();
    CallInfo();
    ShowFuct();
}
