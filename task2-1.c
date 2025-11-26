#include <stdio.h>
/**
@brief WITH_VARIABLE - С использованием третьей переменной
@brief WITHOUTP_VARIABLE  - Без использования третьей переменной
*/
enum SwapMethod {WITH_VARIABLE = 1, WITHOUT_VARIABLE};
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main(void) {
    int a, b, choose;
    printf("Введите значение a:");
    scanf("%d", &a);
    printf("Введите значение b:");
    scanf("%d", &b);
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
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
