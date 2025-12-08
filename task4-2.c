#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
void printArray(int* arr, const size_t size);
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
 * @brief находит индекс минимального элемента массива
 * @param arr массив
 * @param size размер массива
 * @return индекс минимального элемента
 */
int findMinEl(int* arr, const size_t size);
/**
 * @brief находит средний элемент массива (при нечетном размере)
 * @param arr массив
 * @param size размер массива
 * @return значение среднего элемента
 */
int findMiddleEl(int* arr, const size_t size);
/**
 * @brief заменяет минимальный элемент массива на средний
 * @param arr массив
 * @param size размер массива
 */
void replaceMinWithMiddle(int* arr, const size_t size);
/**
 * @brief проверяет, содержит ли число цифру 5
 * @param num число для проверки
 * @return 1 если содержит цифру 5, иначе 0
 */
int containsDigit5(int num);
/**
 * @brief удаляет из массива все элементы, содержащие цифру 5
 * @param arr указатель на массив
 * @param size указатель на размер массива
 */
void removeElementsWithDigit5(int** arr, size_t* size);
/**
 * @brief формирует новый массив A из массива C по правилу
 * @param C исходный массив
 * @param size размер массива
 * @return новый массив A
 */
int* formArrayFromC(int* C, const size_t size);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введенного интервала чисел
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};
int main(void)
{
    srand(time(NULL));
    size_t size = getSize("Введите размер массива C: ");
    if (size % 2 == 0) {
        printf("Для задачи 1 размер должен быть нечетным!\n");
    }
    int* C = malloc(size * sizeof(int));
    if (C == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = getValue();
    switch(choice)
    {
        case RANDOM:
            fillRandom(C, size);
            break;
        case MANUAL:
            fillArray(C, size);
            break;
        default:
            printf("Неверный выбор!\n");
            free(C);
            exit(1);
    }
    printf("Исходный массив C: ");
    printArray(C, size);
    // 1) Заменить минимальный элемент массива на средний
    printf("Задача 1:\n");
    int* C_copy1 = copyArray(C, size);
    printf("Происходит замена минимального элемента на средний\n");
    replaceMinWithMiddle(C_copy1, size);
    printf("Массив после замены минимального элемента на средний: ");
    printArray(C_copy1, size);
    free(C_copy1);
    // 2) Удалить все элементы, содержащие цифру 5
    printf("Задача 2:\n");
    printf("Происходит удаление элементов, содержащих цифру 5\n");
    int* C_copy2 = copyArray(C, size);
    size_t size_copy2 = size;
    removeElementsWithDigit5(&C_copy2, &size_copy2);
    if (size_copy2 == 0) {
        printf("Все элементы были удалены. Массив пуст.\n");
    } else {
        printf("Массив после удаления элементов с цифрой 5 (новый размер: %zu): ", size_copy2);
        printArray(C_copy2, size_copy2);
    }
    free(C_copy2);
    // 3) Сформировать массив A из массива C по правилу
    printf("Задача 3:\n");
    printf("Происходит формирование массива A из массива C\n");
    int* A = formArrayFromC(C, size);
    printf("Сформированный массив A: ");
    printArray(A, size);
    free(A);
    free(C);
    printf("Программа завершена успешно!\n");
    return 0;
}
int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Ошибка ввода!\n");
        abort();
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
        exit(1);
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
void printArray(int* arr, const size_t size)
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
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
// Функции для задач
// 1) Замена минимального элемента на средний
// поиск минимального элемента
int findMinEl(int* arr, const size_t size)
{
    int minElIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[minElIndex])
        {
            minElIndex = i;
        }
    }
    return minElIndex;
}
// поиск среднего элемента
int findMiddleEl(int* arr, const size_t size)
{
    return arr[size / 2];
}
// замена минимального на средний
void replaceMinWithMiddle(int* arr, const size_t size)
{
    int minElIndex = findMinEl(arr, size);
    int middleEl = findMiddleEl(arr, size);
    printf("Минимальный элемент arr[%d] = %d заменяется на средний элемент arr[%zu] = %d\n", minElIndex, arr[minElIndex], size/2, middleEl);
    arr[minElIndex] = middleEl;
}
// 2) Удаление элементов, содержащих цифру 5
// поиск элемента, содержащего цифру 5
int containsDigit5(int el)
{
    if (el < 0) el = -el;
    for (; el > 0; el /= 10)
    {
        if (el % 10 == 5)
        {
            return 1;
        }
    }
    return 0;
}
// удаление элемента, содержащего цифру 5
void removeElementsWithDigit5(int** arr, size_t* size)
{
    size_t newSize = 0;
    for (size_t i = 0; i < *size; i++)
    {
        if (!containsDigit5((*arr)[i]))
        {
            newSize++;
        }
    }
    if (newSize == 0)
    {
        free(*arr);
        *arr = NULL;
        *size = 0;
        return;
    }
    int* newArr = malloc(newSize * sizeof(int));
    if (newArr == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    size_t newIndex = 0;
    for (size_t i = 0; i < *size; i++)
    {
        if (!containsDigit5((*arr)[i]))
        {
            newArr[newIndex++] = (*arr)[i];
        }
        else
        {
            printf("Удален элемент arr[%zu] = %d (содержит цифру 5)\n", i, (*arr)[i]);
        }
    }
    free(*arr);
    *arr = newArr;
    *size = newSize;
}
// 3) Формирование массива A из массива C
int* formArrayFromC(int* C, const size_t size)
{
    int* A = malloc(size * sizeof(int));
    if (A == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            A[i] = pow(C[i], 2);
            printf("A[%zu] = C[%zu]^2 = %d^2 = %d\n", i, i, C[i], A[i]);
        }
        else
        {
            A[i] = 2 * C[i];
            printf("A[%zu] = 2 * C[%zu] = 2 * %d = %d\n", i, i, C[i], A[i]);
        }
    }
    return A;
}
