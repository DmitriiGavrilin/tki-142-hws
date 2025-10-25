#include <stdio.h>
/**
 * @brief Точка входа в программу
 * @return Вернет 0, если программа выполнена корректно. Иначе - 1
 */
int main() {
    int a, b, choose;
    printf("Введите значение a:");
    scanf("%d", &a);
    printf("Введите значение b:");
    scanf("%d", &b);
    printf("1. С использованием третьей переменной\n");
    printf("2. Без использования третьей переменной\n");
    printf("Введите номер варианта:");
    scanf("%d", &choose);
    if (choose == 1)
    {
        int c = a;
        a = b;
        b = c;
    }
    else if (choose == 2)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    printf("После обмена: a = %d, b = %d\n", a, b);
    return 0;
}
