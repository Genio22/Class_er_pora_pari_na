#include <stdio.h>

int main() {
    int x;
    printf("Enter a integer: \n");
    scanf("%d", &x);

    if ((x%5)==0) {
        printf("Divisible by 5\n");
    }
    else {
        printf("Not divisible by 5\n");
    }
    return 0;
}