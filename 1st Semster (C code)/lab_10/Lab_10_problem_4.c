/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int num1, num2, temp;
    int *ptr1, *ptr2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    printf("Before swap: num1 = %d, num2 = %d\n", *ptr1, *ptr2);

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("After swap: num1 = %d, num2 = %d\n", *ptr1, *ptr2);

    return 0;
}



// By sAhAf🙂