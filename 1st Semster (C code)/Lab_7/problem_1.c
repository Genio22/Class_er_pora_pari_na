//sum of two in matrix
#include <stdio.h>
int main()
{
    int i, j, sum = 0;
    printf("Enter the number rows: ");
    scanf("%d", &i);
    printf("Enter the number column: ");
    scanf("%d", &j);
    if (i == j)
    {
        int matrix1[i][j], matrix2[i][j], matrix3[i][j];
        printf("Enter the value of matrix1: \n");
        for(int a = 0; a < i; a++)
        {
            for(int b = 0; b < j; b++)
            {
                scanf("%d", &matrix1[a][b]);
            }
        }
        printf("Enter the value of matrix2: \n");
        for(int a = 0; a < i; a++)
        {
            for(int b = 0; b < j; b++)
            {
                scanf("%d", &matrix2[a][b]);
            }
        }
        //Calculate sum
        printf("Enter the value of matrix3: \n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                matrix3[a][b] = matrix1[a][b] + matrix2[a][b];
            }
        }
        //Print matrix3
        for(int a = 0; a < i; a++)
        {
            for(int b = 0; b < j; b++)
            {
                printf("%d ", matrix3[a][b]);
            }
            printf("\n");
        }
    }

    return 0;
}