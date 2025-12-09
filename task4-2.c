#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
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
 * @brief находит индекс минимального элемента массива
 * @param arr массив
 * @param size размер массива
 * @return индекс минимального элемента
 */
int findMinEl(const int* arr, const size_t size);
/**
 * @brief находит средний элемент массива (при нечетном размере)
 * @param arr массив
 * @param size размер массива
 * @return значение среднего элемента
 */
int findMiddleEl(const int* arr, const size_t size);
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
bool containsDigit5(int num);
/**
 * @brief подсчитывает количество элементов, не содержащих цифру 5
 * @param arr исходный массив
 * @param size размер исходного массива
 * @return количество элементов без цифры 5
 */
size_t getCountWithoutDigit5(const int* arr, const size_t size);
/**
 * @brief создает новый массив без элементов, содержащих цифру 5
 * @param arr исходный массив
 * @param size размер исходного массива
 * @param newarr новый массив (уже выделенная память)
 * @param newSize размер нового массива
 */
void removeElementsWithDigit5(const int* arr, const size_t size, int* newarr, const size_t newSize);
/**
 * @brief формирует новый массив A из массива C по правилу
 * @param C исходный массив
 * @param size размер массива
 * @return новый массив A
 */
int* formArrayFromC(const int* C, const size_t size);
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
        exit(1);
    }
    int* C = allocateArray(size);    
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
    size_t newSize = getCountWithoutDigit5(C, size);
    if (newSize == 0)
    {
        printf("Все элементы массива содержали цифру 5. Очищенный массив пуст!\n");
    }
    else
    {
        int* newC = allocateArray(newSize);
        removeElementsWithDigit5(C, size, newC, newSize);
        printf("Очищенный массив выглядит так (новый размер: %zu):", newSize);
        printArray(newC, newSize);
        free(newC);
    }    
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
// 1) Замена минимального элемента на средний
// поиск минимального элемента
int findMinEl(const int* arr, const size_t size)
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
int findMiddleEl(const int* arr, const size_t size)
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
bool containsDigit5(int el)
{
    if (el < 0) el = -el;
    for (; el > 0; el /= 10)
    {
        if (el % 10 == 5)
        {
            return true;
        }
    }
    return false;
}
// подсчет количества элементов, не содержащих цифру 5
size_t getCountWithoutDigit5(const int* arr, const size_t size)
{
    size_t count = 0;
    for(size_t i = 0; i < size; i++)
    {
        if (!containsDigit5(arr[i]))
        {
            count++;
        }
    }
    return count;
}
// удаление элемента, содержащего цифру 5
void removeElementsWithDigit5(const int *arr, const size_t size, int *newarr, const size_t newSize)
{
    size_t newIndex = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!containsDigit5(arr[i]))
        {
            newarr[newIndex++] = arr[i];
        }
        else
        {
            printf("Элемент arr[%zu] = %d содержит цифру 5 и будет удален из массив\n", i, arr[i]);
        }
    }
}
// 3) Формирование массива A из массива C
int* formArrayFromC(const int* C, const size_t size)
{
    int* A = allocateArray(size);
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
