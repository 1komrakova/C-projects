#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Функция для проверки делимости и возврата нужной строки
// Используем int вместо size_t
void getReplacement(int num, char *output, int output_size) {
    int div5 = (num % 5 == 0);
    int div7 = (num % 7 == 0);
    
    if (div5 && div7) {
        snprintf(output, output_size, "ПЯТЬСЕМЬ");
    } else if (div5) {
        snprintf(output, output_size, "ПЯТЬ");
    } else if (div7) {
        snprintf(output, output_size, "СЕМЬ");
    } else {
        snprintf(output, output_size, "%d", num);
    }
}

int main() {
    srand(time(NULL));
    clock_t start_total, start_part;
    double time_total;
    
    start_total = clock();
    
    int N, M;
    
    // ---- Ввод данных ----
    printf("Введите количество чисел N: ");
    scanf("%d", &N);
    printf("Введите количество столбцов M для матрицы: ");
    scanf("%d", &M);
    
    // ---- Часть 1: Создание input.txt с N случайными числами ----
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка создания input.txt\n");
        return 1;
    }
    
    // Создаем массив случайных чисел через malloc
    int *numbers = (int *)malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка выделения памяти\n");
        fclose(inputFile);
        return 1;
    }
    
    printf("Случайные числа в input.txt:\n");
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 100;
        fprintf(inputFile, "%d ", numbers[i]);
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    fclose(inputFile);
    printf("Числа записаны в input.txt\n\n");
    
    // ---- Часть 1.1: Чтение и замена чисел ----
    start_part = clock();
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия input.txt\n");
        free(numbers);
        return 1;
    }
    
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка создания output.txt\n");
        fclose(inputFile);
        free(numbers);
        return 1;
    }
    
    int num;
    char replacement[50];  // буфер для строки
    fprintf(outputFile, "Результат замены:\n");
    
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &num);
        getReplacement(num, replacement, (int)sizeof(replacement));
        fprintf(outputFile, "%s ", replacement);
        printf("%s ", replacement);
    }
    fprintf(outputFile, "\n");
    printf("\n");
    
    fclose(inputFile);
    fclose(outputFile);
    printf("Результат замены записан в output.txt\n\n");
    
    double time_part1 = ((double)(clock() - start_part)) / CLOCKS_PER_SEC;
    
    // ---- Часть 2: Формирование матрицы ----
    start_part = clock();
    
    int rows = N / M;
    
    if (rows == 0) {
        printf("Ошибка: M больше N, матрицу нельзя сформировать!\n");
        free(numbers);
        return 1;
    }
    
    printf("Формируем матрицу %d x %d (используем %d чисел из %d):\n", rows, M, rows * M, N);
    
    // Выделяем память под матрицу
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти для матрицы\n");
        free(numbers);
        return 1;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти для строки %d\n", i);
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            free(numbers);
            return 1;
        }
    }
    
    // Заполняем матрицу
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = numbers[index++];
        }
    }
    
    // Выводим матрицу
    printf("\nМатрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Выделяем память под суммы
    int *rowSums = (int *)malloc(rows * sizeof(int));
    int *colSums = (int *)malloc(M * sizeof(int));
    
    if (rowSums == NULL || colSums == NULL) {
        printf("Ошибка выделения памяти для сумм\n");
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        free(numbers);
        if (rowSums) free(rowSums);
        if (colSums) free(colSums);
        return 1;
    }
    
    // Обнуляем вручную
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
    }
    for (int j = 0; j < M; j++) {
        colSums[j] = 0;
    }
    
    // Считаем суммы строк
    printf("\nСуммы строк:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            rowSums[i] += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, rowSums[i]);
    }
    
    // Считаем суммы столбцов
    printf("\nСуммы столбцов:\n");
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, colSums[j]);
    }
    
    // Освобождаем память
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(rowSums);
    free(colSums);
    
    double time_part2 = ((double)(clock() - start_part)) / CLOCKS_PER_SEC;
    
    // ---- Общее время ----
    time_total = ((double)(clock() - start_total)) / CLOCKS_PER_SEC;
    
    printf("\n=====================================\n");
    printf("Время замены чисел: %.6f сек\n", time_part1);
    printf("Время работы с матрицей: %.6f сек\n", time_part2);
    printf("ОБЩЕЕ время программы: %.6f сек\n", time_total);
    
    free(numbers);
    
    return 0;
}
