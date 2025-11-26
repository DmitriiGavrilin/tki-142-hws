#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/**
 * @brief функция, определяющая расположение точек
 * @param x1 координата x точки A
 * @param y1 координата y точки A
 * @param x2 координата x точки B
 * @param y2 координата y точки B
 * @param x3 координата x точки C
 * @param y3 координата y точки C
 */
double collinear(double x1, double y1, double x2, double y2, double x3, double y3);
/**
 * @brief вычисляет угол B в треугольнике
 * @param x1 координата x точки A
 * @param y1 координата y точки A
 * @param x2 координата x точки B
 * @param y2 координата y точки B
 * @param x3 координата x точки C
 * @param y3 координата y точки C
 */
double angleValue(double x1, double y1, double x2, double y2, double x3, double y3);
/**
 * @brief считывает значение, 
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Введите координаты точки A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Введите координаты точки B: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Введите координаты точки C: ");
    scanf("%lf %lf", &x3, &y3);
    printf("Точки:\n");
    printf("A(%.2f, %.2f)\n", x1, y1);
    printf("B(%.2f, %.2f)\n", x2, y2);
    printf("C(%.2f, %.2f)\n", x3, y3);
    if (collinear(x1, y1, x2, y2, x3, y3) < DBL_EPSILON) 
    {
        printf("Точки лежат на одной прямой.\n");
    } 
    else 
    {
        printf("Точки не лежат на одной прямой.\n");
        double angle_B = angleValue(x1, y1, x2, y2, x3, y3);
        printf("Угол B в треугольнике: %.2f градусов\n", angle_B);
    }
    return 0;
}
double collinear(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return (x2 - x1) * (y3 - y2) - (x3 - x1) * (y2 - y1);
}
double angleValue(double x1, double y1, double x2, double y2, double x3, double y3) 
{
    double ba_x = x1 - x2;
    double ba_y = y1 - y2;
    double bc_x = x3 - x2;
    double bc_y = y3 - y2;
    double scalar_product = ba_x * bc_x + ba_y * bc_y;
    double length_ba = sqrt(ba_x * ba_x + ba_y * ba_y);
    double length_bc = sqrt(bc_x * bc_x + bc_y * bc_y);
    if (length_ba == 0 || length_bc == 0) {
        printf("Ошибка: длина вектора не должна быть равна 0\n");
        return -1;
    }
    double cos_angle = scalar_product / (length_ba * length_bc);
    if (cos_angle > 1.0) cos_angle = 1.0;
    if (cos_angle < -1.0) cos_angle = -1.0;
    double angle_deg = acos(cos_angle) * 180.0 / M_PI;
    return angle_deg;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка!\n");
        abort();
    }
    return value;
}
void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Введено неверное значение\n");
        abort();
    }
}
