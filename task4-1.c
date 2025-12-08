#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();
/**
 * @brief выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива
 */
size_t getSize(char* message);
/**
 * @brief считывает каждое из значений элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);
/**
 * @brief выводит элементы массива в стилизованном виде
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);
/**
 * @brief заполняет массив случайными числами, выбранными из введенного интервала чисел
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);
/**
 * @brief создает копию массива
 * @param arr массив
 * @param size размер массива
 * @return копия исходного массива
 */
int* copyArray(const int* arr, const size_t size);
/**
 * @brief выделяет память для массива целых чисел заданного размера с проверкой успешности выделения
 * @param size размер массива (количество элементов)
 * @return указатель на выделенную память для массива
 * @note в случае ошибки выделения памяти выводит сообщение об ошибке и завершает программу
 */
int* allocateArray(const size_t size);
/**
 * @brief ищет сумму отрицательных элементов массива, кратных 10
 * @param arr массив
 * @param size размер массива
 * @return сумма отрицательных элементов массива, кратных 10
 */
int sumNegativeMultiplesOf10(const int* arr, const size_t size);
/**
 * @brief меняет местами первые k элементов в обратном порядке
 * @param arr массив
 * @param size размер массива
 * @param k введенное число элементов
 * @return измененную копию исходного массива
 */
void reverseFirstKElements(int* arr, const size_t size, const int k);
/**
 * @brief ищет пару соседних элементов массива, произведение которых равно введенному значению произведения
 * @param arr массив
 * @param size размер массива
 * @param targetProduct введенное значение произведения
 * @return соседние элементы массива, произведение которых равно введенному значению произведения
 */
int hasAdjacentPairWithProduct(const int* arr, const size_t size, const int targetProduct);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введенного интервала чисел
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};
/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    srand(time(NULL));
    size_t size = getSize("Введите размер массива: ");
    int* arr = allocateArray(size);
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = getValue();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("Неверный выбор!\n");
            free(arr);
            exit(1);
    }
    printf("Исходный массив: ");
    printArray(arr, size);
    // 1) Найти сумму отрицательных элементов, кратных 10
    printf("Задача 1:\n");
    int sum = sumNegativeMultiplesOf10(arr, size);
    printf("Сумма отрицательных элементов, кратных 10: %d\n", sum);
    // 2) Заменить первые k элементов на те же в обратном порядке
    printf("Задача 2:\n");
    printf("Введите k (не больше %zu): ", size);
    int k = getValue(); 
    int* arrCopy = copyArray(arr, size);
    reverseFirstKElements(arrCopy, size, k);
    printf("Массив после замены первых %d элементов: ", k);
    printArray(arrCopy, size);
    free(arrCopy);
    // 3) Проверить наличие пары соседних элементов с заданным произведением
    printf("Задача 3\n");
    if (size > 1)
    {
        printf("Введите число для проверки произведения: ");
        int targetProduct = getValue();
        if (!hasAdjacentPairWithProduct(arr, size, targetProduct))
        {
            printf("Пара соседних элементов с произведением %d не найдена\n", targetProduct);
        }
    }
    else
    {
        printf("Массив слишком мал для поиска пар элементов (нужно хотя бы 2 элемента)\n");
    }
    free(arr);
    return 0;
}
int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}
size_t getSize(char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Размер должен быть положительным числом!\n");
        abort();
    }
    return (size_t)value;
}
void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент arr[%zu]: ", i);
        arr[i] = getValue();
    }
}
void printArray(const int* arr, const size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
    printf("\n");
}
void fillRandom(int* arr, const size_t size)
{
    printf("Введите начало диапазона: ");
    int start = getValue();
    printf("Введите конец диапазона: ");
    int end = getValue();
    if(start >= end)
    {
        printf("Ошибка! Конечное значение должно быть больше начального\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}
int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = allocateArray(size);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
int* allocateArray(const size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти для массива размера %zu!\n", size);
        exit(1);
    }
    return arr;
}
// Функции для задач
// 1) Найти сумму отрицательных элементов, кратных 10
int sumNegativeMultiplesOf10(const int* arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0 && arr[i] % 10 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}
// 2) Заменить первые k элементов на те же в обратном порядке
void reverseFirstKElements(int* arr, const size_t size, const int k)
{
    for (int i = 0; i < k / 2; i++)
    {
        int reserveValue = arr[i];
        arr[i] = arr[k - i - 1];
        arr[k - i - 1] = reserveValue;
    }
}
// 3) Проверить наличие пары соседних элементов с заданным произведением
int hasAdjacentPairWithProduct(const int* arr, const size_t size, const int targetProduct)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] * arr[i + 1] == targetProduct)
        {
            printf("Найдена пара соседних элементов с произведением %d: ", targetProduct);
            printf("arr[%zu] = %d и arr[%zu] = %d\n",  i, arr[i], i + 1, arr[i + 1]);
            return 1;
        }
    }
    return 0;
}
