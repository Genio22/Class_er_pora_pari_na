/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int sum = 0;
    int mat1[3][4], mat2[4][3], result[3][3];
    printf("Enter a the first martix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter a the first martix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d  ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Enter a the second martix\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }

    // print result
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// By sAhAf🙂