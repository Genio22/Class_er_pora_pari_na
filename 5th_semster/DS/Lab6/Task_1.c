#include <stdio.h>

void THO(int n, char beg, char aux, char des)
{
    if (n == 1)
    {
        printf("Move from %c to %c\n", beg, des);
        return;
    }
    THO(n - 1, beg, des, aux);
    THO(1, beg, aux, des);
    THO(n - 1, aux, beg, des);
}

void digit_sum(int num)
{
    static int sum = 0;
    if (num == 0)
    {
        printf("Sum: %d\n", sum);
        return;
    }

    sum = num % 10 + sum;
    digit_sum(num / 10);
}

void gcd(int a, int b)
{
    if (b == 0)
    {
        printf("GCD: %d\n", a);
        return;
    }
    if (a == 0)
    {
        printf("GCD: %d\n", b);
        return;
    }
    gcd(b, a % b);
}

void printf_down(int num)
{
    if (num == 1)
    {
        printf("%d\n", num);
        return;
    }
    printf("%d", num);
    printf_down(num - 1);
}

int fibo(int n)
{

    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

void sum_fibo(int n)
{
    static int sum = 0;
    if (n == 0)
    {
        printf("Sum: %d\n", sum);
        return;
    }
    sum += fibo(n);
    sum_fibo(n - 1);
}

// int sum_fibo(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     return fibo(n) + sum_fibo(n - 1);
// }

int main()
{

    gcd(36, 12);
    digit_sum(42);
    THO(4, 'A', 'B', 'C');

    sum_fibo(3);

    printf_down(6);
    
    return 0;
}
