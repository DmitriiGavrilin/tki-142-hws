#include <stdio.h>
#include <math.h>
/**
 * @brief Рассчитывает расстояние между двумя точками
 * @param point координата
 * @return возвращает рассчитанное расстояние между двумя точками
 */
double getDistance(const double x1, const double x2, const double y1, const double y2);
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void)
{
    double x1, x2, y1, y2;
    printf("Координата 1-ой точки равна:");
    scanf("%lf %lf", &x1, &y1);
    printf("Координата 2-ой точки равна:");
    scanf("%lf %lf", &x2, &y2);
    printf("Расстояние равно %.2lf\n", getDistance(x1, x2, y1, y2));
    return 0;
}
double getDistance(const double x1, const double x2, const double y1, const double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
