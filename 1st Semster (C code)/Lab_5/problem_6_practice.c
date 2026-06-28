/*The greatest common divisor (GCD) of two integers is the largest integer that evenly divides each of
the two numbers. Write a function gcd thatreturnsthe greatest common divisor oftwo integers.*/
#include <stdio.h>
#include <math.h>

int a, b, result = 1;

int main()
{
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);
    for (int i = 1; i <= (a<b ? a:b); i++)
    {
            if ((a % i == 0) && (b % i == 0))
            {
                result = i;
            }
    }
    printf("The GCD of %d & %d is %d", a, b, result);
    return 0;
}

