/*Problem 5
Write a function integerPower(base, exponent) that returnsthe value of baseexponent.
For exam- ple, integerPower( 3, 4 ) = 3 * 3 * 3 * 3. Assume that exponent is a positive, nonzero integer, and base is an integer.
Function integerPower should be used to control the calculation.
Do not use any math library functions.*/
#include <stdio.h>

int a, b, n, result = 1;

int power(int a, int b)
{
    for (int i = 1; i <= b; i++)
    {
        result *= a;
    }
    return result;
}
int main()
{
    printf("Enter base: ");
    scanf("%d", &a);
    printf("Enter power: ");
    scanf("%d", &b);
    int final_result = power(a, b);
    printf("%d", final_result);
    return 0;
}
