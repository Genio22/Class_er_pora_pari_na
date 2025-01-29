/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>


int main() {
    int num;
    int *ptr;

    printf("Enter a number: ");
    scanf("%d", &num);

    ptr = &num;
    (*ptr)++; 

    printf("Incremented value = %d\n", num);

    return 0;
}





// By sAhAf🙂