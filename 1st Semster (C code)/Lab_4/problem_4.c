/*Write a C program to calculate x y where x is base (an integer) and y is exponent (an integer)
as follows. The program should have a while repetition statement.*/
#include <stdio.h>

int main()
{
    int expo, result = 1, base;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &expo);
    if (expo < 0)
    {
        printf("Negative exponents are not supported right now. Sorry :) ");
    }
    else
    {
        int count = 0;
        while (count < expo)
        {
            result *= base;
            count++;
        }
        printf("%d^%d = %d\n", base, expo, result);
    }

    return 0;
}