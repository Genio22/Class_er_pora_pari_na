#include <stdio.h>

int main() {
    int x,y;
    printf("Enter math score: ");
    scanf("%d", &x);
    
    printf("Enter Science score: ");
    scanf("%d", &y);

    if (x>=70 && y>=70) {
        if (x>=90 && y>=90) {
        printf("Eligible for scholarship\n");
        }
        else{
        printf("Eligible\n");
        }
    }
    else {
        printf("You are badly fucked up\n");
    }
    return 0;
}
