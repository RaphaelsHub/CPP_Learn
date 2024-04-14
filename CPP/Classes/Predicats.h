#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsGreaterThan0(int num)
{
    return num > 0;
}
class Bum
{
public:
    int num = 0;
    Bum(int num)
    {
        this->num = num;
    };
    ~Bum() = default;
    bool operator()(int num)
    {
        return IsGreaterThan0(num);
    }
};

void ShowPred()
{
    vector<Bum> Nums = {Bum(3), Bum(45), Bum(23), Bum(-34), Bum(-5), Bum(-23), Bum(-34)};

    int result = count_if(Nums.begin(), Nums.end(), Nums.front()); // вместо NUMSFRONT должна быть функция, но мы передаем ссылка на элемент колекции, и вызываем функтор, который свою очередь является переопределением аоператора к=круглые скобки

    cout << result << endl;
}