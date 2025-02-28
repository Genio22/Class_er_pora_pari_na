/* Write a program to input a 2D array of size MxN (M rows and N columns) and display it
in a tabular format, where each element is printed in a grid-like structure with proper
alignment. */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();
    int array[m][n];
    printf("hi\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// By sAhAf🙂