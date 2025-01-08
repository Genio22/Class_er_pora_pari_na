#include <stdio.h>

int main(){
    int w;
    scanf("%d", &w);
    switch (w) {
        case 1:
            printf("January has 31 days");
            break;
        case 2:
            printf("February has 28 days");
            break;
        case 3:
            printf("March has 31 days");
            break;
        case 4:
            printf("April has 30 days");
            break;
        case 5:
            printf("May has 31 days");
            break;
        case 6:
            printf("June has 30 days");
            break;
        case 7:
            printf("July has 31 days");
            break;
    }
    return 0;
}
