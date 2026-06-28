/*Check wheather the two matrix are equal or not*/

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
        int space =i*j, count = 0;
        int matrix1[i][j], matrix2[i][j], matrix3[i][j];
        printf("Enter the value of matrix1: \n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                scanf("%d", &matrix1[a][b]);
            }
        }
        printf("Enter the value of matrix2: \n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                scanf("%d", &matrix2[a][b]);
            }
        }
        //check
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                if (matrix1[a][b] == matrix2[a][b]){
                    count++;
                }
                // scanf("%d", &matrix2[a][b]);
            }
        }
        // Debugeing
        // printf("%d", count);
        if (space == count){
            printf("The matrixs are equal by value. :)");
        }
        else{
            printf("The matrixs are not equal by value. :(");
        }
    }
    else{
        printf("The matrixs are not equal by dimension. :(");
    }
    return 0;
}