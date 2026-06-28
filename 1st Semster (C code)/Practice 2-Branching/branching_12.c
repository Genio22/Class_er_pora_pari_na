#include <stdio.h>

int main() {

    int x;
    printf("Enter a number: \n");
    scanf("%d", &x);

    if (x>=1 && x<=10) {
        printf("Small\n");
    }
    else if (x>=11 && x<=100) {
        printf("Medium\n");
    }
    else if (x>=101) {
        printf("Large\n");
    }
    else {
        printf("none\n");
    }
    return 0;
}
