//Check if a matrix is upper triangle
#include <stdio.h>

int main()
{
    int i, j;
    // Take matrix dimensions as input
    printf("Enter the number of rows: ");
    scanf("%d", &i);
    printf("Enter the number of columns: ");
    scanf("%d", &j);
    if (i == j)
    {
        int matrix1[i][j];
        int isUpperTriangular = 1;


        printf("Enter the values for matrix1:\n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                scanf("%d", &matrix1[a][b]);
            }
        }
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {

                if (a > b && matrix1[a][b] == 0)
                {
                    isUpperTriangular = 0;
                    break;
                }
            }
        }
        if (isUpperTriangular == 0)
            {
                printf("Matrix1 is an upper triangular matrix.\n");
            }
            else
            {
                printf("Matrix1 is not an upper triangular matrix.\n");
            }
    }
    return 0;
}