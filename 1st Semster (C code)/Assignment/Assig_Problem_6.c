/*6. Print the Sum of the Series 1+1/2+1/3+....1/n

Input an integer n and calculate the sum of the harmonic series up to the nth term. Use a loop to
add 1
i
for each i from 1 to n.*/

#include <stdio.h>

int main()
{
    int n;
    float sum = 0;

    printf("Enter total nth summation: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum = sum + (1.0 / i);
        printf("%f\n", sum);
    }
    printf("The sum of the harmonic series up to %d terms is: %f\n", n, sum);
    return 0;
}