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
 * @brief вычисляет факториал числа
 * @param n - число для вычисления факториала
 * @return факториал числа n
 */
long long factorial(int n);
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
long long factorial(int n)
{
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
double getSumN(const int n)
{
    double result = 0.0;
    for (int k = 1; k <= n; k++)
    {
        double el = pow(-1, k) * (double)factorial(k) / (double)factorial(4 + k);
        result += el;
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
    double result = 0.0;
    double el = 0.0;
    for (int k = 1; k < 1000; k++)
    {
        el = pow(-1, k) * (double)factorial(k) / (double)factorial(4 + k);
        result += el;
        if (fabs(el) <= e) {
            break;
        }
    }
    return result;
}
