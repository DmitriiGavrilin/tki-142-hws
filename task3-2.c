#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();
/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();
/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);
/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);
/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);
/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите значение n:");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.10lf\n", n, getSumN(n));
    printf("Введите e:");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма последовательности с точностью %lf равна %.10lf\n", e, getSumE(e));
    return 0;
}
int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Ошибка\n");
        exit(1);
    }
    return value;
}
void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Ошибка\n");
        exit(1);
    }
}
double getRecurent(const int i)
{
    return (-1.0) * i / (i + 4.0);
}
double getSumN(const int n)
{
    if (n <= 0) return 0.0;
    double current = -1.0 / 120.0;
    double result = current;
    for (int k = 2; k <= n; k++)
    {
        current *= getRecurent(k);
        result += current;
    }
    return result;
}
double getDouble()
{
    double value = 0.0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка\n");
        exit(1);
    }
    return value;
}
double getSumE(const double e)
{
    double current = -1.0 / 120.0;
    double result = current;
    for (int k = 2; k < 1000; k++)
    {
        current *= getRecurent(k);
        result += current;
        if (fabs(current) <= e) {
            break;
        }
    }
    return result;
}
