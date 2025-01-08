#include <stdio.h>

int main() {
    int x;
    printf("Enter years: \n");
    scanf("%d", &x);

    if ((x%4)==0) {
        printf("%d is leap year\n", x);
    }
    else if ((x%400)==0) {
        printf("%d is leap year\n", x);
    }
    else {
        printf("%d is not a leap year\n", x);
    }
    return 0;
}