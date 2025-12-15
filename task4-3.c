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
 * @brief вставляет перед всеми строками, первый элемент которых делится на 3, строку из нулей
 * @param arr указатель на массив
 * @param rows указатель на количество строк
 * @param columns количество столбцов
 */
void insertZeroRows(int*** arr, size_t* rows, const size_t columns);
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
    srand(time(NULL));
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    if (columns == 0) {
        printf("Количество столбцов должно быть больше 0!\n");
        exit(1);
    }
    int** arr = allocateArray(rows, columns);
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
            exit(1);
    }
    printf("Исходный массив:\n");
    printArray((const int* const*)arr, rows, columns);
    printf("Задача 1:");
    int** arrCopy1 = copyArray((const int* const*)arr, rows, columns);
    replaceMaxWithZero(arrCopy1, rows, columns);
    printf("Массив после замены максимального элемента каждой строки нулем:\n");
    printArray((const int* const*)arrCopy1, rows, columns);
    printf("Задача 2:");
    int** arrCopy2 = copyArray((const int* const*)arr, rows, columns);
    size_t newRows = rows;
    insertZeroRows(&arrCopy2, &newRows, columns);
    printf("Массив после вставки строк из нулей:\n");
    printf("Новый размер: %zu строк × %zu столбцов\n", newRows, columns);
    printArray((const int* const*)arrCopy2, newRows, columns);
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
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите элемент arr[%zu][%zu]: ", i, j);
            arr[i][j] = getValue();
        }
    }
}
void printArray(const int* const* arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fillRandom(int** arr, const size_t rows, const size_t columns)
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
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % (end - start + 1) + start;
        }
    }
}
int** allocateArray(const size_t rows, const size_t columns)
{
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
    if (arr != NULL)
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (arr[i] != NULL)
            {
                free(arr[i]);
            }
        }
        free(arr);
    }
}
int** copyArray(const int* const* arr, const size_t rows, const size_t columns)
{
    int** copyArr = allocateArray(rows, columns);
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    
    return copyArr;
}
// Функции для задач
// Задача 1/ Замена максимального элемента каждой строки нулем
void replaceMaxWithZero(int** arr, const size_t rows, const size_t columns) {
    for (size_t i = 0; i < rows; i++) 
    {
        int max = arr[i][0];
        for (size_t j = 1; j < columns; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
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
// Задача 2/ Вставка строк из нулей
bool isFirstElementDivisibleBy3(const int* const* arr, const size_t rowIndex) {
    return (abs(arr[rowIndex][0]) % 3 == 0);
}
void insertZeroRows(int*** arr, size_t* rows, const size_t columns) {
    size_t rowsToInsert = 0;
    for (size_t i = 0; i < *rows; i++) {
        if (isFirstElementDivisibleBy3((const int* const*)(*arr), i)) {
            rowsToInsert++;
        }
    }
    if (rowsToInsert == 0) {
        printf("Нет строк, у которых первый элемент делится на 3\n");
        return;
    }
    printf("Найдено %zu строк, у которых первый элемент делится на 3\n", rowsToInsert);
    size_t newRows = *rows + rowsToInsert;
    int** newArr = malloc(newRows * sizeof(int*));
    if (newArr == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    for (size_t i = 0; i < newRows; i++){
        newArr[i] = NULL;
    }
    size_t newIndex = 0;
    for (size_t i = 0; i < *rows; i++) {
        if (isFirstElementDivisibleBy3((const int* const*)(*arr), i)) {
            newArr[newIndex] = malloc(columns * sizeof(int));
            if (newArr[newIndex] == NULL) {
                printf("Ошибка выделения памяти!\n");
                for (size_t j = 0; j < newIndex; j++) {
                    free(newArr[j]);
                }
                free(newArr);
                exit(1);
            }
            for (size_t j = 0; j < columns; j++) {
                newArr[newIndex][j] = 0;
            }
            printf("Вставлена строка из нулей перед строкой %zu\n", i);
            newIndex++;
        }
        newArr[newIndex] = malloc(columns * sizeof(int));
        if (newArr[newIndex] == NULL) {
            printf("Ошибка выделения памяти!\n");
            for (size_t j = 0; j <= newIndex; j++) {
                free(newArr[j]);
            }
            free(newArr);
            exit(1);
        }
        for (size_t j = 0; j < columns; j++) {
            newArr[newIndex][j] = (*arr)[i][j];
        }
        newIndex++;
    }
    if (*arr != NULL) {
        for (size_t i = 0; i < *rows; i++) {
            free((*arr)[i]);
        }
        free(*arr);
    }
    *arr = newArr;
    *rows = newRows;
}
