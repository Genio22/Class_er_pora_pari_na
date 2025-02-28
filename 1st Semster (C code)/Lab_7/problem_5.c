/* Change the diagonals of a matrix and interchange them, then print the matrix */

#include <stdio.h>

int main() {
    int i, j, c;

    printf("Enter the number of rows: ");
    scanf("%d", &i);
    printf("Enter the number of columns: ");
    scanf("%d", &j);

    
    if (i == j && i > 0 && i % 2 != 0) {
        int matrix[i][j];

        
        printf("Enter the elements of the matrix:\n");
        for (int a = 0; a < i; a++) {
            for (int b = 0; b < j; b++) {
                scanf("%d", &matrix[a][b]);
            }
        }

        // Swap the diagonals
        for (int f = 0; f < i; f++) {
            c = matrix[f][f];                  
            matrix[f][f] = matrix[f][i - 1 - f]; 
            matrix[f][i - 1 - f] = c;
        }

        
        printf("Matrix after swapping diagonals:\n");
        for (int a = 0; a < i; a++) {
            for (int b = 0; b < j; b++) {
                printf("%d ", matrix[a][b]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix must be square with an odd size.\n");
    }

    return 0;
}
