#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
Вероятность выпадения блэкджэка в казина p = (N+10)/100
Найти математеческое распределение для опыта проводимого 9 раз подряд, где Х случайная дискретная величина
*/
/*
 * 1. В классе 28 человек
 * 2. 10 пацанов
 * 3. 17 девочек
 * 4. 1 трансвистит
 * 5. Найдите вероятнотсь выбрать кого-то наугад
 */

extern "C"
{
    void P();
    void D();
    float Chance(int z,int y);
    float propability(float a, float sum);
}
float probaility(float a, float sum)
{
    return a / sum;
}
float Chance(int z, int y)
{
    float a = 1, b = 1, c = 1;
    int dif = y - z;
    if (z == 0 || z == y)
        return a;

    else
    {
        for (int i = y; i >= 1; i--)
            a = a * i;
        for (int n = dif; n >= 1; n--)
            c = c * n;
        for (int r = z; r >= 1; r--)
            b = b * r;
        float result = a / (c * b);
        return (float)result;
    }
}
void P()
{
    float boys, girls, trans;

    do
    {
        static int count = 0;
        if (count > 0)
            printf("Error. Please input number positive!\n\n\n");

        printf("Enter the amount of boys: ");
        scanf("%f", &boys);
        printf("Enter the amount of girls: ");
        scanf("%f", &girls);
        printf("Enter the amount of trans: ");
        scanf("%f", &trans);

        count++;
    } while (trans < 0 || boys < 0 || girls < 0);

    float sum = boys + girls + trans;
    boys = probaility(boys, sum);
    girls = probaility(girls, sum);
    trans = probaility(trans, sum);

    printf("\n");
    printf("Chance to take a boy %f\n", boys);
    printf("Chance to take a girl %f\n", girls);
    printf("Chance to take a trans %f\n", trans);
}
void D()
{
    // system("chcp 1251"); смена кодировки, если файл в кодировке cp1251
    system("chcp 65001"); // смена кодировки, если файл в кодировке atf-8
    system("cls");

    int NUM, amount;

    printf("Введите ваше место нахождение в журнале: ");
    scanf("%d", &NUM);
    printf("Введите количество раз, которое будет проводиться опыт: ");
    scanf("%d", &amount);

    float P = (float)(NUM + 10) / 100;
    float Q = 1 - P;
    const int N = (amount + 1);
    double PX[N];

    for (int x = 0; x < N; x++)
        PX[x] = pow(P, x) * pow(Q, amount - x) * Chance(x, amount);
    printf("\n");

    for (int x = 0; x < N; x++)
        printf("%d - %f\n", x, PX[x]);

    double mat = 0, dis = 0;
    for (int x = 0; x < N; x++)
        mat = mat + PX[x] * x;

    for (int x = 0; x < N; x++)
        dis = dis + PX[x] * x * x;
    dis = dis + mat * mat;

    double otlonenie = sqrt(dis);

    printf("Математическое ожидание равно %f\n", mat);
    printf("Дисперсия равна %f\n", dis);
    printf("Стандартное отклонение равно %f\n", otlonenie);

}


int main(int argc, char* argv[])
{
    
    return 0;
}
