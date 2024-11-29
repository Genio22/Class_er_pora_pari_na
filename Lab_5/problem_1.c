/*Problem 1
Write a C program to input any number from user and find cube of the given number using function.*/

#include <stdio.h>

int a, result = 1;

int find_cude(int a)
{
    for (int i = 1; i < 4; i++)
    {
        result *= a;
    }
    return result;
}

int main()
{
    printf("Enter the number: ");
    scanf("%d", &a);
    int f_result = find_cude(a);
    printf("The cudic value of (%d)^3 is %d", a, f_result);
    return 0;
}
