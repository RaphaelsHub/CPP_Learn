#pragma once

class my_class
{
private:
    int value_;

public:
    my_class(int a){value_ = a;}
    ~my_class() = default;
};

inline void MakePointer()
{
    std::auto_ptr<my_class> autoPtr(new my_class(1));
    //Используем auto_ptr (устаревший, не рекомендуется использовать)

    std::unique_ptr<my_class> uniquePtr(new my_class(2));
    // Используем unique_ptr (используется для уникального владения ресурсом)

    std::shared_ptr<my_class> sharedPtr1(new my_class(3));
    // Используем shared_ptr (используется для общего владения ресурсом)

    std::shared_ptr<my_class> sharedPtr2 = sharedPtr1;
    // Создаем второй shared_ptr, который также ссылается на тот же объект

    // Используем auto для создания умного указателя (должно быть удобным)
    auto autoPtr1 = std::make_shared<my_class>(4);
    auto auroPtr2 = autoPtr1;

    // Используем умный указатель unique_ptr (должно быть удобным)
    auto uniqueShared = std::make_unique<my_class>(5);
}

