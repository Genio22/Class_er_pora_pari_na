/*The factorial of a nonnegative integer n is written n! (pronounced “n factorial”) and is defined
as follows:
n! = n · (n – 1) · (n – 2) · ... · 1 (for values of n greater than 1)
and n! = 1 (for n = 0 or n = 1).
For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120.
Write a program that reads a nonnegative integer, and computes and prints its factorial.*/
#include <stdio.h>

int main()
{
    int result = 1, factor;
    printf("Enter a positive integer: ");
    scanf("%d", &factor);
    if (factor < 0)
    {
        printf("Factorial is not possible for negative numbers. Try again.\n");
    }
    else
    {
        for (int count = 1; count <= factor; count++)
        {
            result *= count;
        }
        printf("Factorial of %d is %d\n", factor, result);
    }

    return 0;
}