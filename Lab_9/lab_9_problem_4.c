/*Write a function that takes an integer N as parameter. And print Hello World N times using
recursion. Remember that you cannot use any loop in this program.*/

/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

void repeat_print(int n)
{
    if (n == 0)
        return;
    printf("Hello World!\n");
    repeat_print(n - 1);
}

int main()
{
    int n;
    printf("How many times do you want 'Hello World!' to be print? \n");
    scanf("%d", &n);
    repeat_print(n);
    return 0;
}

// By sAhAf🙂
