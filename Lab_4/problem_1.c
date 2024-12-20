/*You will take an integer number from the user. You have to find the summation of all the digits.*/
#include <stdio.h>

int main()
{
    int digit = 0, sum = 0, num;
    scanf("%d", &num);
    if (num < 0)
    {
        num = -num;
    
    while (num>0)
    {
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
    printf("%d", sum);
    }
    else 
    {
    while (num > 0)
    {
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
    printf("%d", sum);
    }
    return 0;
}