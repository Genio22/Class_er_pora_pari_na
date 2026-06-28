/* Design a structure named ”Car” to store details like car ID, model, and rental rate per day. Write a
C program to input data for three cars, calculate the total rental cost for a specified number of
days, and display the results. */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct car
{
    char id[100];
    char model[100];
    float rental_rate_per_day;
} c;

int main()
{
    int n;
    char target[100];
    // float sum = 0, average = 0;
    printf("Enter the number of Cars: ");
    scanf("%d", &n);
    getchar();

    struct car c[n];

    if (n <= 0)
    {
        printf("Invalid number of Cars. Please enter a positive integer.\n");
        return 0; // exit
    }

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for car: %d\n", i + 1);
        printf("ID: ");
        scanf("%19[0-9a-zA-Z]", &c[i].id);
        getchar();
        printf("Model: ");
        scanf("%19[0-9a-zA-Z]", &c[i].model);
        getchar();
        printf("Rental rate per day: ");
        scanf("%f", &c[i].rental_rate_per_day);
        getchar();
    }
    int days = 0, found_n = 0;
    float t_cost = 0;
    printf("\n\nTarget Car: ");
    scanf("%19[0-9a-zA-Z]", &target);
    getchar();

    printf("How many day it is rented for: ");
    scanf("%d", &days);
    getchar();

    // Linear Search
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(c[i].id, target))
        {
            t_cost = c[i].rental_rate_per_day * days;
            found_n = i;
        }
    }

    printf("\n\nFound!!\n");
    printf("Car %d\n", found_n + 1);
    printf("ID: %s\n", c[found_n].id);
    printf("Model: %s\n", c[found_n].model);
    printf("Rental Rate: %.2f\n", c[found_n].rental_rate_per_day);
    printf("Total rental cost: %.2f", t_cost);

    return 0;
}

/*sir i have improvise the question i have add search. i hope you donot mind. the reason i add the search is beasue it was making more reasonalable to me.*/
// By sAhAf🙂