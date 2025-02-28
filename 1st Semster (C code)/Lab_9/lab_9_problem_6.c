/* Implement a recursive function to find the n-th Fibonacci number, where n is provided as input.
Display the entire sequence up to n using the function.
*/
// version 2
#include <stdio.h>
#include <math.h>
#include <string.h>

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

void print_fibo(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", fibo(i));
    }
}

int main()
{
    int n;
    printf("Enter the number to get Fibonacci series upto that posion printed: ");
    scanf("%d", &n);

    print_fibo(n);

    return 0;
}

/* sir, i it was hard to visuaize the recursion of fibonaki series.
So i took help from internet and copied the this formula "F(n)=F(n−1)+F(n−2) for 𝑛>2". rest of the part is done by me.*/

/*
// version 1
void fibo(int n)
{
    int a = 0, b = 1, c = 0;

    printf("%d, ", a);
    printf("%d, ", b);
    int i = 3;
    while (i <= n)
    {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
        i++;
    }
}

int main()
{
    int n, result;
    printf("Enter the number to get Fibonacci series upto that posion printed: ");
    scanf("%d", &n);

    fibo(n);

    return 0;
}
*/

// By sAhAf🙂