#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    //input dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    // Input dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if matrices can be multiplied
    if (c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
