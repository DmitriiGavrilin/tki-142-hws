#include <stdio.h>
#include <stdlib.h>
/**
@brief WITH_VARIABLE - С использованием третьей переменной
@brief WITHOUT_VARIABLE  - Без использования третьей переменной
*/
enum SwapMethod {WITH_VARIABLE = 1, WITHOUT_VARIABLE};
/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getValue();
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void) {
    printf("Введите значение a:");
    double a = getValue();
    printf("Введите значение b:");
    double b = getValue();
    int choose;
    printf("%d. С использованием третьей переменной\n", WITH_VARIABLE);
    printf("%d. Без использования третьей переменной\n", WITHOUT_VARIABLE);
    printf("Введите номер варианта:");
    scanf("%d", &choose);
    switch (choose) {
        case WITH_VARIABLE: {
            int c = a;
            a = b;
            b = c;
            printf("Использован метод с временной переменной\n");
            break;
        }
        case WITHOUT_VARIABLE: {
            a = a + b;
            b = a - b;
            a = a - b;
            printf("Использован арифметический метод без временной переменной\n");
            break;
        }
        default:
            printf("Ошибка: выбран неверный вариант! Допустимые значения: %d или %d\n", WITH_VARIABLE, WITHOUT_VARIABLE);
            return 1;
    }
    printf("После обмена: a = %lf, b = %lf\n", a, b);
    return 0;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка\n");
        abort();
    }
    return value;
}
