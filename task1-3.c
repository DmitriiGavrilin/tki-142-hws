#include <stdio.h>
/**
 * @brief Рассчитывает расстояние между двумя точками
 * @param weight масса тела
 * @param square площадь поверхности тела
 * @param g ускорение свободного падения
 * @return возвращает рассчитанное расстояние между двумя точками
 */
double getPressure(const double weight, const double square, const double g);
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void)
{
    double weight, square, g;
    printf("Введите значение массы тела: ");
    scanf("%lf", &weight);
    printf("Введите значение площади тела: ");
    scanf("%lf", &square);
    printf("Введите значение ускорения свободного падения: ");
    scanf("%lf", &g);
    printf("Давление тела на поверхность равно: %.4lf\n", getPressure(weight, square, g));
    return 0;
}
double getPressure(const double weight, const double square, const double g)
{
    return weight * g / square;
}
