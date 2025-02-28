/*
Season Finder: Take a month number (1–12) as input and print the season
(e.g., "Winter," "Spring," etc.) using a switch statement.
*/
#include <stdio.h>

int main() {
    int month;
    printf("Enter a month number (1–12): ");
    scanf("%d", &month);

    switch (month) {
        case 4: 
        case 5:
            printf("Season: Summer (Grishmo)");
            break;
        case 6: 
        case 7:
            printf("Season: Rainy Season (Borsha)");
            break;
        case 8: 
        case 9:
            printf("Season: Autumn (Shorot)");
            break;
        case 10: 
        case 11:
            printf("Season: Late Autumn (Hemonto)");
            break;
        case 12: 
        case 1:
            printf("Season: Winter (Sheet)");
            break;
        case 2: 
        case 3:
            printf("Season: Spring (Boshonto)");
            break;
        default:
            printf("Invalid month number!");
    }

    return 0;
}
