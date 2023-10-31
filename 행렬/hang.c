#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("행렬의 행 수: ");
    scanf("%d", &rows);
    printf("행렬의 열 수: ");
    scanf("%d", &cols);

    int** matrix1 = (int**)malloc(rows * sizeof(int*));
    int** matrix2 = (int**)malloc(rows * sizeof(int*));
    int** resultMatrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int*)malloc(cols * sizeof(int));
        matrix2[i] = (int*)malloc(cols * sizeof(int));
        resultMatrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("첫 번째 행렬:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("두 번째 행렬:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("두 행렬의 합:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}

