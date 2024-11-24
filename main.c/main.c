#include <stdio.h>
#include <string.h>

void l4p1()
{
    /* You will take an integer number from the user. You have to find the summation of all the digits. */
    int digit = 0, sum = 0, num;

    // Prompt the user to enter an integer number
    printf("Enter an integer number to calculate the sum of its digits: ");
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0)
    {
        // Convert the number to positive for summing its digits
        num = -num;
        printf("You entered a negative number. We will convert it to positive.\n");

        // Loop to sum the digits of the number
        while (num > 0)
        {
            digit = num % 10;  // Extract the last digit
            sum = sum + digit; // Add the digit to the sum
            num = num / 10;    // Remove the last digit
        }

        // Output the sum of digits
        printf("The sum of the digits is: %d\n", sum);
    }
    else
    {
        // Loop to sum the digits of the number
        while (num > 0)
        {
            digit = num % 10;  // Extract the last digit
            sum = sum + digit; // Add the digit to the sum
            num = num / 10;    // Remove the last digit
        }

        // Output the sum of digits
        printf("The sum of the digits is: %d\n", sum);
    }

    // Clear the input buffer
    while (getchar() != '\n')
        ;
}

void l4p2()
{
    /*In this problem, you will develop a program that can find how many times an integer number
    can be divided by Two (2).*/
    int a, num = 0, count = 0;

    printf("Enter a integer: ");
    scanf("%d", &a);
    if (a == 0)
    {
        printf("The number 0 cannot be divided by 2.\n");
    }

    int original = a;
    while ((a % 2) == 0 && a != 0)
    {
        a /= 2;
        count++;
    }
    printf("The number %d can be divided by 2 exactly %d times.", original, count);
    while (getchar() != '\n')
        ;
}

void l4p3()
{
    /*You will take several integer numbers as inputs until the user enters -1. Then calculate the
    difference between the Highest and Lowest number.*/
    int num = 0, max = -999999, min = 999999;
    printf("Enter integers (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        else if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    int dif = max - min;
    printf("Difference between highest and lowest: %d\n", dif);
    while (getchar() != '\n')
        ;
}

void l4p4()
{
    /*Write a C program to calculate x y where x is base (an integer) and y is exponent (an integer)
    as follows. The program should have a while repetition statement.*/
    int expo, result = 1, base;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &expo);
    if (expo < 0)
    {
        printf("Negative exponents are not supported right now. Sorry :) ");
    }
    else
    {
        int count = 0;
        while (count < expo)
        {
            result *= base;
            count++;
        }
        printf("%d^%d = %d\n", base, expo, result);
    }
    while (getchar() != '\n')
        ;
}

void l4p5()
{
    /*The factorial of a nonnegative integer n is written n! (pronounced “n factorial”) and is defined
    as follows:
    n! = n · (n – 1) · (n – 2) · ... · 1 (for values of n greater than 1)
    and n! = 1 (for n = 0 or n = 1).
    For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120.
    Write a program that reads a nonnegative integer, and computes and prints its factorial.*/

    int result = 1, factor;
    printf("Enter a positive integer: ");
    scanf("%d", &factor);
    if (factor < 0)
    {
        printf("Factorial is not possible for negative numbers. Try again.\n");
    }
    else
    {
        for (int count = 1; count <= factor; count++)
        {
            result *= count;
        }
        printf("Factorial of %d is %d\n", factor, result);
    }
    while (getchar() != '\n')
        ;
}

void l4p6()
{
    /*Write a program in C to check whether a number is a palindrome or not.
    Test Data :
    Input a number: 121
    Expected Output :
    121 is a palindrome number.*/

    int n, rem, original, rev = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    for (original = n; n != 0; n /= 10)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
    }
    if (original == rev)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);
    while (getchar() != '\n')
        ;
}

int main()
{
    int a, max_input = 20;
    char input[20];

    printf("Hi there! Do you want to enter in the program? (If not enter 'exit'): ");
    fgets(input, sizeof(input), stdin);
    // printf("Welcome to pari_na_class. What's your name? ");
    while (strcmp(input, "exit\n") != 0)
    {
        printf("Choose a lab to check a program from it (enter the lab name or type 'exit' to quit):\n");
        printf("1. lab1\n");
        printf("2. lab2\n");
        printf("3. lab3\n");
        printf("4. lab4\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        else if ((strcmp(input, "lab4\n") == 0) || (strcmp(input, "lab 4\n") == 0))
        {
            printf("\nYou selected Lab 4. Here are the available programs:\n");
            while (1)
            {
                printf("\nChoose a program to run (type 'exit' to return to the main menu):\n");
                printf("1. Problem 1: Sum of Digits\n");
                printf("2. Problem 2: Divide by 2 Count\n");
                printf("3. Problem 3: Max-Min Difference\n");
                printf("4. Problem 4: Exponentiation\n");
                printf("5. Problem 5: Factorial Calculation\n");
                printf("6. Problem 6: Palindrome Check\n");
                printf("Enter your choice: ");
                fgets(input, sizeof(input), stdin);

                if (strcmp(input, "exit\n") == 0)
                {
                    printf("Returning to the main menu...\n");
                    break;
                }
                else if ((strcmp(input, "problem1\n") == 0) || (strcmp(input, "problem 1\n") == 0) || (strcmp(input, "1\n") == 0))
                {
                    l4p1();
                }
                else if ((strcmp(input, "problem2\n") == 0) || (strcmp(input, "problem 2\n") == 0) || (strcmp(input, "2\n") == 0))
                {
                    l4p2();
                }
                else if ((strcmp(input, "problem3\n") == 0) || (strcmp(input, "problem 3\n") == 0) || (strcmp(input, "3\n") == 0))
                {
                    l4p3();
                }
                else if ((strcmp(input, "problem4\n") == 0) || (strcmp(input, "problem 4\n") == 0) || (strcmp(input, "4\n") == 0))
                {
                    l4p4();
                }
                else if ((strcmp(input, "problem5\n") == 0) || (strcmp(input, "problem 5\n") == 0) || (strcmp(input, "5\n") == 0))
                {
                    l4p5();
                }
                else if ((strcmp(input, "problem6\n") == 0) || (strcmp(input, "problem 6\n") == 0) || (strcmp(input, "6\n") == 0))
                {
                    l4p6();
                }
                else
                {
                    printf("Invalid choice. Please try again.\n");
                }
            }
        }
        else
        {
            printf("Invalid choice. Please select a valid lab or type 'exit' to quit.\n");
        }
        printf("\nDo you want to continue in the program? (Type 'exit' to quit or press Enter to continue): ");
        fgets(input, sizeof(input), stdin);
    }
    return 0;
}