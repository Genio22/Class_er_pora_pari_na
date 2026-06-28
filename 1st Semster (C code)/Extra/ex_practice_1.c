/*Write a program that calculates the parking fee based on the number of hours a car has been parked.
The first hour is free, each of the next four hours costs 20 units,
and each additional hour Costs 30 units. Prompt the user to enter the number of hours the car has been parked and display the fee.*/

#include <stdio.h>

int main()
{
    int hour, fee = 40;
    printf("Enter the total hour parking: ");
    scanf("%d", &hour);
    // switch (hour){
    //     case 1:
    //         printf("You are Free to go.");
    //     case 4
    // }
    // printf("%d\n", hour);
    if (hour == 1)
    {
        printf("You are Free to go.");
    }
    else if (1 < hour && hour <= 4)
    {
        printf("Your fee is 40$. Pay!!");
    }

    else if (hour > 4)
    {
        for (int i = 4; i < hour; i++)
        {
            fee = fee + 30;
        }
        printf("Your fee is %d$. Pay!!", fee);
    }
    return 0;
}