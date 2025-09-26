#include <stdio.h>
#include <math.h>
/**
 * @brief Рассчитывает значение функции B
 * @param x значение параметра x
 * @param y значение параметра y
 * @param z значение параметра z
 * @return Рассчитанные значения
 */
double getB(const double x, const double y, const double z);
/**
 * @brief Рассчитывает значение функции A
 * @param x значение параметра\ x
 * @param y значение параметра y
 * @param z значение параметра z
 * @return Рассчитанные значения
 */
double getA(const double x, const double y, const double z);
/**
 * @brief Точка входа программы
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void)
{
    const double x = 0.61;
    const double y = 3.4;
    const double z = 16.5;
    printf("A = %.6f\n", getA(x, y, z));
    printf("B = %.9f\n", getB(x, y, z));
    return 0;
}
double getA(const double x, const double y, const double z)
{
    return pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + z / pow(x + y, .5);
}
double getB(const double x, const double y, const double z)
{
    return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}
