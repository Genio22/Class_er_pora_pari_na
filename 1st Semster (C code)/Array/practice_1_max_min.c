/*1. Find the Maximum and Minimum Elements in an Array
Write a program to find and print the largest and smallest numbers in a given array.
• Input: An array of integers.
• Output: The maximum and minimum values in the array.
• Logic: Use a single loop to iterate through the array, comparing each element with the
current maximum and minimum values.*/

/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

void find_max_min(int a, int mat1[])
{
    int max = mat1[0], min = mat1[0];
    for (int i = 0; i < a; i++)
    {
        if (mat1[i] > max)
        {
            max = mat1[i];
        }
        else
        {
            min = mat1[i];
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void array_input(int a, int mat1[])// give size and array name 
{
    printf("Enter a matrix: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &mat1[i]);
    }
}
int main()
{
    int a;

    printf("Enter a size: ");
    scanf("%d", &a);
    
    int mat1[a];

    array_input(a, mat1);
    find_max_min(a, mat1); // WHY mat1 not mat[] because mat1 will pass whole array

    return 0;
}

// By sAhAf🙂
