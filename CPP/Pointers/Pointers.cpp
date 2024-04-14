#include<iostream>
#include<memory>

/*
data_type *pointerName;
Есть два способа использования указателя:
1.	без символа * - фактический адрес ячейки памяти, куда ссылается указатель
2.	с символом * - значение, хранящееся в памяти
Операции для работы с указателями в Си:
1.	операция * (звездочка) — позволяет получить значение объекта по его адресу - определяет значение переменной, которое содержится по адресу, содержащемуся в указателе
2.	операция & (амперсанд) — позволяет определить адрес переменной.
сhar c; - переменная
char *p; - указатель
p = &c; - p = адрес c
*/

//Functions
std::string GetDataFromBD() { return "BD"; }
std::string GetDataFromCEO() { return "CEO"; }
std::string GetDataFromCustomer() { return "CUSTOMER"; }

//Pointer to function
void ShowData(std::string (*Data)())
{
    std::cout << Data() << "\n";
}

class MyClass
{
private:
    int value;

public:
    MyClass(int a) : value(a)
    {
    }

    ~MyClass() = default;
};

int main()
{
    int x = 0;
    int* pX = &x;
    int** pXy = &pX;
    x = **pXy;
    std::cout << *pX << "\n";


    std::auto_ptr<MyClass> autoPtr(new MyClass(1));
    //Используем auto_ptr (устаревший, не рекомендуется использовать)

    std::unique_ptr<MyClass> uniquePtr(new MyClass(2));
    // Используем unique_ptr (используется для уникального владения ресурсом)

    std::shared_ptr<MyClass> sharedPtr1(new MyClass(3));
    // Используем shared_ptr (используется для общего владения ресурсом)

    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
    // Создаем второй shared_ptr, который также ссылается на тот же объект

    // Используем auto для создания умного указателя (должно быть удобным)
    auto autoPtr1 = std::make_shared<MyClass>(4);
    auto auroPtr2 = autoPtr1;

    // Используем умный указатель unique_ptr (должно быть удобным)
    auto uniqueShared = std::make_unique<MyClass>(5);

    //Calling fuction
    ShowData(GetDataFromBD);
    std::string (*Data)() = GetDataFromBD;
    ShowData(Data);
}
