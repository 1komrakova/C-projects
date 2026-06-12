#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    clock_t start_total = clock();
    
    int N, M;
    printf("Введите количество чисел N: ");
    scanf("%d", &N);
    printf("Введите количество столбцов M: ");
    scanf("%d", &M);
    
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка создания input.txt\n");
        return 1;
    }
    
    int *numbers = (int *)malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка выделения памяти\n");
        fclose(inputFile);
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 100;
        fprintf(inputFile, "%d ", numbers[i]);
    }
    fclose(inputFile);
    
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
    fprintf(outputFile, "Результат замены:\n");
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &num);
        if (num % 5 == 0 && num % 7 == 0) {
            fprintf(outputFile, "ПЯТЬСЕМЬ ");
        } else if (num % 5 == 0) {
            fprintf(outputFile, "ПЯТЬ ");
        } else if (num % 7 == 0) {
            fprintf(outputFile, "СЕМЬ ");
        } else {
            fprintf(outputFile, "%d ", num);
        }
    }
    fprintf(outputFile, "\n");
    fclose(inputFile);
    fclose(outputFile);
    
    int rows = N / M;
    if (rows == 0) {
        printf("Ошибка: M больше N\n");
        free(numbers);
        return 1;
    }
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = numbers[index++];
        }
    }
    
    printf("\nМатрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] % 5 == 0 && matrix[i][j] % 7 == 0) {
                printf("%-10s ", "ПЯТЬСЕМЬ");
            } else if (matrix[i][j] % 5 == 0) {
                printf("%-10s ", "ПЯТЬ");
            } else if (matrix[i][j] % 7 == 0) {
                printf("%-10s ", "СЕМЬ");
            } else {
                printf("%-10d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    
    int *rowSums = (int *)malloc(rows * sizeof(int));
    int *colSums = (int *)malloc(M * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
    }
    for (int j = 0; j < M; j++) {
        colSums[j] = 0;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
    
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }
    
    printf("\nСуммы строк:\n");
    for (int i = 0; i < rows; i++) {
        printf("Строка %d: %d\n", i + 1, rowSums[i]);
    }
    
    printf("\nСуммы столбцов:\n");
    for (int j = 0; j < M; j++) {
        printf("Столбец %d: %d\n", j + 1, colSums[j]);
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(rowSums);
    free(colSums);
    free(numbers);
    
    clock_t end_total = clock();
    double time_total = ((double)(end_total - start_total)) / CLOCKS_PER_SEC;
    printf("\nВремя работы программы: %.6f секунд\n", time_total);
    
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    clock_t start_total = clock();
    
    int N, M;
    printf("Введите количество чисел N: ");
    scanf("%d", &N);
    printf("Введите количество столбцов M: ");
    scanf("%d", &M);
    
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка создания input.txt\n");
        return 1;
    }
    
    int *numbers = (int *)malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка выделения памяти\n");
        fclose(inputFile);
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 100;
        fprintf(inputFile, "%d ", numbers[i]);
    }
    fclose(inputFile);
    
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
    fprintf(outputFile, "Результат замены:\n");
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &num);
        if (num % 5 == 0 && num % 7 == 0) {
            fprintf(outputFile, "ПЯТЬСЕМЬ ");
        } else if (num % 5 == 0) {
            fprintf(outputFile, "ПЯТЬ ");
        } else if (num % 7 == 0) {
            fprintf(outputFile, "СЕМЬ ");
        } else {
            fprintf(outputFile, "%d ", num);
        }
    }
    fprintf(outputFile, "\n");
    fclose(inputFile);
    fclose(outputFile);
    
    int rows = N / M;
    if (rows == 0) {
        printf("Ошибка: M больше N\n");
        free(numbers);
        return 1;
    }
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = numbers[index++];
        }
    }
    
    printf("\nМатрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] % 5 == 0 && matrix[i][j] % 7 == 0) {
                printf("%-10s ", "ПЯТЬСЕМЬ");
            } else if (matrix[i][j] % 5 == 0) {
                printf("%-10s ", "ПЯТЬ");
            } else if (matrix[i][j] % 7 == 0) {
                printf("%-10s ", "СЕМЬ");
            } else {
                printf("%-10d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    
    int *rowSums = (int *)malloc(rows * sizeof(int));
    int *colSums = (int *)malloc(M * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
    }
    for (int j = 0; j < M; j++) {
        colSums[j] = 0;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
    
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }
    
    printf("\nСуммы строк:\n");
    for (int i = 0; i < rows; i++) {
        printf("Строка %d: %d\n", i + 1, rowSums[i]);
    }
    
    printf("\nСуммы столбцов:\n");
    for (int j = 0; j < M; j++) {
        printf("Столбец %d: %d\n", j + 1, colSums[j]);
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(rowSums);
    free(colSums);
    free(numbers);
    
    clock_t end_total = clock();
    double time_total = ((double)(end_total - start_total)) / CLOCKS_PER_SEC;
    printf("\nВремя работы программы: %.6f секунд\n", time_total);
    
    return 0;
}
