#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief считывает значение, 
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void)
{
    const double a = 2.5;
    double y;
    printf("Введите значение х:");
    double x = getValue();
    if (x > a)
    {
        double sin_x = sin(x);
        y = x * pow(sin_x, 2);
    }
    else {
        double cos_x = cos(x);
        y = x * pow(cos_x, 2);
    }
    printf("При значении x: %.2f\n", x);
    printf("Значение функции равно: %.2f\n", y);
    return 0;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}
