/*6. Print the Sum of the Series

Input an integer n and calculate the sum of the harmonic series up to the nth term. Use a loop to
add 1
i
for each i from 1 to n.*/

#include <stdio.h>

int main()
{
    float n, sum = 0;
    printf("Enter total nth summmation: ");
    scanf("%f", &n);
    for (int i = 1; i <= n; i++)
    {
        sum = sum + (1 / i);
        printf("%d\n", sum);
    }
    printf("%f", sum);
    return 0;
}