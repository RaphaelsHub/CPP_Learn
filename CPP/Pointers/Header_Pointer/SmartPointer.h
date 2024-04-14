#pragma once

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

void MakePointer()
{
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
}

