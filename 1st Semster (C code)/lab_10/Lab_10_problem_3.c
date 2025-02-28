/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int num1, num2, result;
    int *ptr1, *ptr2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    result = (*ptr1) * (*ptr2); 

    printf("Multiplication result = %d\n", result);

    return 0;
}




// By sAhAf🙂