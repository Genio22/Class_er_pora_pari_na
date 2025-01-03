/* Create a recursive function to calculate the sum of the digits of a given integer n. For example, if n
= 1234, the result should be 1 + 2 + 3 + 4 = 10. */
#include <stdio.h>
#include <math.h>
#include <string.h>

int sum(int n)
{

    int d,r;
    if (n ==0) return 0;
    d = n % 10;
    r = d + sum(n/10);
    return r;

}

int main()
{
    int n, sum1;
    printf("Enter the number to get its digit sum: ");
    scanf("%d", &n);
    sum1 = sum(n);
    printf("%d", sum1);
    return 0;
}

