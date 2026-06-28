#include <stdio.h>

int main() {
    int x,y;
    printf("Enter 1st number: \n");
    scanf("%d", &x);
    
    printf("Enter 2nd number: \n");
    scanf("%d", &y);

    if (x>y) {
        printf("x IS greater than y\n");
    }
    else if (x<y) {
        printf("x IS less than y\n");
    }
    else if (x==y) {
        printf("x IS equal to y\n");
    }
    else {
        printf("none\n");
    }
    return 0;
}
