#include <stdio.h>

int main() {
    int x;
    printf("Enter the temperature: \n");
    scanf("%d", &x);


    if (x<10) {
        printf("Cold\n");
    }
    else if (x>10 && x<25) {
        printf("Warm\n");
    }
    else if (x>25) {
        printf("Hot\n");
    }
    else {
        printf("none\n");
    }
    return 0;
}
