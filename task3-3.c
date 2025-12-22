#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble(void);
/**
 * @brief проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */
void checkMinMax(const double min, const double max);
/**
 * @brief проверяет, что шаг функции больше нуля
 * @param step значение шага функции
 */
void checkStep(const double step);
/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);
/**
 * @brief вычисляет значение функции
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double targetFunc(const double x);
/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс (начинается с 1)
 * @param x значение параметра x
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);
/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */
double getSumE(const double e, const double x);
/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    printf("Введите min (0.1):\n");
    const double min = getDouble();
    printf("Введите max (1.0):\n");
    const double max = getDouble();
    checkMinMax(min, max);
    printf("Введите шаг:\n");
    const double step = getDouble();
    checkStep(step);
    printf("Введите точность e (0.0001):\n");
    const double e = getDouble();
    checkPositive(e);
    printf("Результаты вычислений:\n");
    printf("x\t\tf(x)=(1+2x²)e^(x²)\tS (сумма ряда)\n");    
    for (double x = min; x < max + step; x += step) {
        printf("%.6lf\t%.6lf\t\t%.6lf\n", x, targetFunc(x), getSumE(e, x));
    }
    return 0;
}
double getDouble(void)
{
    double value = 0;
    int result = scanf("%lf", &value);
    if (result != 1){
        fprintf(stderr, "Ошибка ввода");
        exit(1);
    }
    return value;
}
void checkMinMax(const double min, const double max) {
    if (min >= max) {
        printf("Max должно быть больше чем min.");
        exit(1);
    }
}
void checkStep(const double step) {
    if (step < DBL_EPSILON) {
        fprintf(stderr, "Шаг должен быть больше 0");
        exit(1);
    }
}
void checkPositive(const double value)
{
    if (value < 0)
    {
        fprintf(stderr, "Ошибка ввода. Значение должно быть положительным.");
        exit(1);
    }
}
double targetFunc(const double x) {
    return (1.0 + 2.0 * x * x) * exp(x * x);
}
double getRecurent(const int i, const double x)
{
    return ((2.0 * i + 1.0) * x * x) / (i * (2.0 * i - 1.0));
}
double getSumE(const double e, const double x)
{
    double current = 1.0;
    double result = current;
    for (int i = 1; fabs(current) > e; i++)
    {
        current *= getRecurent(i, x);
        result += current;
    }
    return result;
}
