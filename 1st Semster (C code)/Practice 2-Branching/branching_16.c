#include <stdio.h>

int main() {
    int x;
    printf("Enter number: \n");
    scanf("%d", &x);


    if (x>0) {
        if ((x%2)==0) {
            printf("Positive Even\n");
        }
        else{
            printf("Positive Odd\n");
        }
    }
    else if (x!=0 && x<0) {
        if ((x%2)==0) {
            printf("Negetive Even\n");
        }
        else{
            printf("Negetive Odd\n");
        }
    }
    else {
        printf("none\n");
    }
    return 0;
}
