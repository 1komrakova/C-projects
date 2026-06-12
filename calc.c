#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int n;
    printf("Введите размер квадратных матриц: ");
    scanf("%d", &n);
    
    FILE *inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Ошибка создания input.txt\n");
        return 1;
    }
    
    int **matrixA = (int **)malloc(n * sizeof(int *));
    int **matrixB = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrixA[i] = (int *)malloc(n * sizeof(int));
        matrixB[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
            fprintf(inputFile, "%d ", matrixA[i][j]);
        }
        fprintf(inputFile, "\n");
    }
    fprintf(inputFile, "\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(inputFile, "%d ", matrixB[i][j]);
        }
        fprintf(inputFile, "\n");
    }
    
    fclose(inputFile);
    
    for (int i = 0; i < n; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);
    
    clock_t start = clock();
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия input.txt\n");
        return 1;
    }
    
    matrixA = (int **)malloc(n * sizeof(int *));
    matrixB = (int **)malloc(n * sizeof(int *));
    int **sumResult = (int **)malloc(n * sizeof(int *));
    int **mulResult = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrixA[i] = (int *)malloc(n * sizeof(int));
        matrixB[i] = (int *)malloc(n * sizeof(int));
        sumResult[i] = (int *)malloc(n * sizeof(int));
        mulResult[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &matrixA[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &matrixB[i][j]);
        }
    }
    fclose(inputFile);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mulResult[i][j] = 0;
            for (int k = 0; k < n; k++) {
                mulResult[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка создания output.txt\n");
        return 1;
    }
    
    fprintf(outputFile, "Сумма матриц:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(outputFile, "%d ", sumResult[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    
    fprintf(outputFile, "\nПроизведение матриц:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(outputFile, "%d ", mulResult[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    
    fclose(outputFile);
    
    clock_t end = clock();
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f секунд\n", time_spent);
    
    for (int i = 0; i < n; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(sumResult[i]);
        free(mulResult[i]);
    }
    free(matrixA);
    free(matrixB);
    free(sumResult);
    free(mulResult);
    
    return 0;
}
