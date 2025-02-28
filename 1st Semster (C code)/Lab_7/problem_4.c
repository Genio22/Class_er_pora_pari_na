//sum of diagonal element in matrix
#include <stdio.h>
int main()
{
    int i, j, sum = 0;
    printf("Enter the number rows: ");
    scanf("%d", &i);
    printf("Enter the number column: ");
    scanf("%d", &j);
    int matrix[i][j];
    printf("Enter the value of matrix: \n");
    for(int a = 0; a < i; a++)
    {
        for(int b = 0; b < j; b++)
        {
            scanf("%d", &matrix[a][b]);
            if (a==b)
            {
                sum+=matrix[a][b];
            }
        }
    }
    printf("Sum = %d", sum);
    return 0;
}