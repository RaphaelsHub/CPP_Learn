#include <iostream>
#define FUNCTION(a) ((a) < 0 ? -(a) : (a))
#define LEFT 1
#define RIGHT (LEFT + LEFT)
#define TEXT "All right\n\continue"

/*
 *Препроцессоры это ряд иструкций регламентирующие работу компилятора - эти инструкции называются директиваим препроцессора #define LEFT 1

 *Директивы условной компиляции - #elif #if  #else #endif - Эти директивы позволяют выбирать компилируемые части программы в зависимости от значения константного выражения.

 * #if def #ifndef - Если определен макрос если не определен макрос

 *#undef - Удалить значение определенной константы
 *
 *#line устанавливает счетчик строк
 */
using namespace std;

int main()
{
    cout << LEFT << " " << RIGHT << " " << TEXT;
    cout << (FUNCTION(10));

#if RIGHT > 5
    cout << "it is true";
#elif RIGHT == 2
    cout << "it is true";
#else
    cout << "it is not true";
#endif


#ifdef LEFT
    cout << "is here";
#else
    printf("Not Here");
#endif

#ifndef RALPH
    printf("not here");
#endif

    return 0;
}
