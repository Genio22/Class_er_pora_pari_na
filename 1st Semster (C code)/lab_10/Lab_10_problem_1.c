/* Problem 1: Add two numbers using pointers */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int num1, num2, sum;
    int *ptr1, *ptr2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    sum = *ptr1 + *ptr2;
    printf("Sum = %d\n", sum);

    return 0;
}



// By sAhAf🙂