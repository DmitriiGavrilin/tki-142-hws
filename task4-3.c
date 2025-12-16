#include <stdio.h>
#include <stdlib.h>
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
size_t getSize(const char* message);
/**
 * @brief считывает каждое из значений элементов массива
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief выводит элементы массива в стилизованном виде
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void printArray(const int* const* arr, const size_t rows, const size_t columns);
/**
 * @brief заполняет массив случайными числами, выбранными из введенного интервала чисел
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);
/**
 * @brief создает копию массива
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return копия исходного массива
 */
int** copyArray(const int* const* arr, const size_t rows, const size_t columns);
/**
 * @brief выделяет память для массива целых чисел заданного размера с проверкой успешности выделения
 * @param rows количество строк
 * @param columns количество столбцов
 * @return указатель на выделенную память для массива
 * @note в случае ошибки выделения памяти выводит сообщение об ошибке и завершает программу
 */
int** allocateArray(const size_t rows, const size_t columns);
/**
 * @brief освобождает память, выделенную под двумерный массив
 * @param arr массив
 * @param rows количество строк
 */
void freeArray(int** arr, const size_t rows);
/**
 * @brief заменяет максимальный элемент каждой строки нулем
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void replaceMaxWithZero(int** arr, const size_t rows, const size_t columns);
/**
 * @brief проверяет, делится ли первый элемент строки на 3
 * @param arr массив
 * @param rowIndex индекс строки
 * @return true если первый элемент делится на 3, иначе false
 */
bool isFirstElementDivisibleBy3(const int* const* arr, const size_t rowIndex);
/**
 * @brief подсчитывает количество строк, перед которыми нужно вставить строки из нулей
 * @param arr массив
 * @param rows количество строк
 * @return количество строк для вставки
 */
size_t countRowsToInsert(const int* const* arr, const size_t rows);
/**
 * @brief создает новый массив с вставленными строками из нулей
 * @param sourceArr исходный массив
 * @param sourceRows количество строк в исходном массиве
 * @param columns количество столбцов
 * @param destRows указатель для сохранения количества строк в новом массиве
 * @return новый массив или NULL при ошибке
 */
int** createArrayWithZeroRows(const int* const* sourceArr, const size_t sourceRows, const size_t columns, size_t* destRows);
/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введенного интервала чисел
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    srand((unsigned int)time(NULL));
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    if (columns == 0 || rows == 0) {
        printf("Количество строк и столбцов должно быть больше 0!\n");
        return 1;
    }
    int** arr = allocateArray(rows, columns);
    if (arr == NULL) {
        printf("Не удалось выделить память для массива!\n");
        return 1;
    }
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = getValue();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, rows, columns);
            break;
        case MANUAL:
            fillArray(arr, rows, columns);
            break;
        default:
            printf("Неверный выбор!\n");
            freeArray(arr, rows);
            return 1;
    }
    printf("Исходный массив:\n");
    printArray((const int* const*)arr, rows, columns);
    printf("Задача 1:\n");
    int** arrCopy1 = copyArray((const int* const*)arr, rows, columns);
    if (arrCopy1 == NULL) {
        printf("Не удалось создать копию массива для задачи 1!\n");
        freeArray(arr, rows);
        return 1;
    }
    replaceMaxWithZero(arrCopy1, rows, columns);
    printf("Массив после замены максимального элемента каждой строки нулем:\n");
    printArray((const int* const*)arrCopy1, rows, columns);
    printf("Задача 2:\n");
    size_t newRows = 0;
    int** arrCopy2 = createArrayWithZeroRows((const int* const*)arr, rows, columns, &newRows);
    if (arrCopy2 != NULL) {
        printf("Массив после вставки строк из нулей:\n");
        printf("Новый размер: %zu строк × %zu столбцов\n", newRows, columns);
        printArray((const int* const*)arrCopy2, newRows, columns);
    }
    freeArray(arr, rows);
    freeArray(arrCopy1, rows);
    freeArray(arrCopy2, newRows);
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
size_t getSize(const char* message)
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
void fillArray(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL || rows == 0 || columns == 0) {
        printf("Неверные параметры для заполнения массива!\n");
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] == NULL) {
            printf("Ошибка: строка %zu равна NULL!\n", i);
            continue;
        }
        for (size_t j = 0; j < columns; j++) {
            printf("Введите элемент arr[%zu][%zu]: ", i, j);
            arr[i][j] = getValue();
        }
    }
}
void printArray(const int* const* arr, const size_t rows, const size_t columns)
{
    if (arr == NULL) {
        printf("Массив пуст (NULL)!\n");
        return;
    }
    if (rows == 0 || columns == 0) {
        printf("Размеры массива некорректны!\n");
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] == NULL) {
            printf("(Строка %zu: NULL)\n", i);
            continue;
        }
        for (size_t j = 0; j < columns; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL || rows == 0 || columns == 0) {
        printf("Неверные параметры для заполнения случайными числами!\n");
        return;
    }
    printf("Введите начало диапазона: ");
    int start = getValue();
    printf("Введите конец диапазона: ");
    int end = getValue();
    if(start >= end)
    {
        printf("Ошибка! Конечное значение должно быть больше начального\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] == NULL) {
            printf("Ошибка: строка %zu равна NULL!\n", i);
            continue;
        }
        for (size_t j = 0; j < columns; j++) {
            arr[i][j] = rand() % (end - start + 1) + start;
        }
    }
}
int** allocateArray(const size_t rows, const size_t columns)
{
    if (rows == 0 || columns == 0) {
        return NULL;
    }
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти для массива!\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Ошибка выделения памяти для строки %zu!\n", i);
            for (size_t j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }
    return arr;
}
void freeArray(int** arr, const size_t rows)
{
    if (arr == NULL) {
        return;
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
int** copyArray(const int* const* arr, const size_t rows, const size_t columns)
{
    if (arr == NULL || rows == 0 || columns == 0) {
        printf("Неверные параметры для копирования массива!\n");
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] == NULL) {
            printf("Ошибка: исходная строка %zu равна NULL!\n", i);
            return NULL;
        }
    }
    int** copyArr = allocateArray(rows, columns);
    if (copyArr == NULL) {
        printf("Не удалось выделить память для копии массива!\n");
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}
void replaceMaxWithZero(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL || rows == 0 || columns == 0) {
        printf("Неверные параметры для замены максимумов!\n");
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] == NULL) {
            printf("Строка %zu равна NULL, пропускаем\n", i);
            continue;
        }
        int max = arr[i][0];
        int maxCount = 1;
        for (size_t j = 1; j < columns; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxCount = 1;
            } else if (arr[i][j] == max) {
                maxCount++;
            }
        }
        if (maxCount > 0) {
            int replaced = 0;
            for (size_t j = 0; j < columns; j++) {
                if (arr[i][j] == max) {
                    arr[i][j] = 0;
                    replaced++;
                }
            }
            if (replaced > 0) {
                printf("В строке %zu заменено %d максимальных элементов (значение %d) на 0\n", i, replaced, max);
            }
        }
    }
}
bool isFirstElementDivisibleBy3(const int* const* arr, const size_t rowIndex)
{
    if (arr == NULL || arr[rowIndex] == NULL) {
        return false;
    }
    return (arr[rowIndex][0] % 3 == 0);
}
size_t countRowsToInsert(const int* const* arr, const size_t rows)
{
    if (arr == NULL || rows == 0) {
        return 0;
    }
    size_t rowsToInsert = 0;
    for (size_t i = 0; i < rows; i++) {
        if (arr[i] != NULL && isFirstElementDivisibleBy3(arr, i)) {
            rowsToInsert++;
        }
    }
    return rowsToInsert;
}
int** createArrayWithZeroRows(const int* const* sourceArr, const size_t sourceRows, const size_t columns, size_t* destRows)
{
    if (sourceArr == NULL || destRows == NULL || sourceRows == 0 || columns == 0) {
        printf("Неверные параметры!\n");
        if (destRows) *destRows = 0;
        return NULL;
    }
    size_t rowsToInsert = countRowsToInsert(sourceArr, sourceRows);
    *destRows = sourceRows + rowsToInsert;
    if (rowsToInsert == 0) {
        printf("Нет строк для вставки, возвращаем копию исходного массива\n");
        return copyArray(sourceArr, sourceRows, columns);
    }
    printf("Найдено %zu строк, у которых первый элемент делится на 3\n", rowsToInsert);
    int** destArr = allocateArray(*destRows, columns);
    if (destArr == NULL) {
        printf("Не удалось выделить память для нового массива!\n");
        *destRows = 0;
        return NULL;
    }
    size_t destIndex = 0;
    for (size_t i = 0; i < sourceRows; i++) {
        if (isFirstElementDivisibleBy3(sourceArr, i)) {
            for (size_t j = 0; j < columns; j++) {
                destArr[destIndex][j] = 0;
            }
            printf("Вставлена строка из нулей перед строкой %zu\n", i);
            destIndex++;
        }
        for (size_t j = 0; j < columns; j++) {
            destArr[destIndex][j] = sourceArr[i][j];
        }
        destIndex++;
    }
    return destArr;
}
