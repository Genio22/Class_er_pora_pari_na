#include <stdio.h>
#include <string.h>

// Function to calculate the summation of all digits in an integer
void l4p1()
{
    int digit = 0, sum = 0, num;
    printf("\nEnter an integer number to find the sum of its digits: ");
    scanf("%d", &num);

    // Convert negative numbers to positive for digit summation
    if (num < 0)
    {
        num = -num;
    }

    // Extract and sum each digit
    while (num > 0)
    {
        digit = num % 10; // Get the last digit
        sum += digit;     // Add it to the sum
        num /= 10;        // Remove the last digit
    }

    printf("The sum of the digits is: %d\n", sum);

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

// Function to determine how many times a number can be divided by 2
void l4p2()
{
    int a, count = 0;

    printf("\nEnter an integer to check how many times it can be divided by 2: ");
    scanf("%d", &a);

    if (a == 0)
    {
        printf("The number 0 cannot be divided by 2.\n");
    }
    else
    {
        int original = a;
        while (a % 2 == 0)
        {
            a /= 2; // Divide by 2
            count++;
        }
        printf("The number %d can be divided by 2 exactly %d times.\n", original, count);
    }

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

// Function to find the difference between the highest and lowest numbers entered
void l4p3()
{
    int num = 0, max = -999999, min = 999999;

    printf("\nEnter integers one by one (type -1 to stop):\n");

    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
        { // Stop input on -1
            break;
        }
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }

    int dif = max - min;
    printf("The difference between the highest (%d) and lowest (%d) numbers is: %d\n", max, min, dif);

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

// Function to calculate x^y using a while loop
void l4p4()
{
    int expo, result = 1, base;

    printf("\nEnter the base number: ");
    scanf("%d", &base);
    printf("Enter the exponent (positive integer): ");
    scanf("%d", &expo);

    if (expo < 0)
    {
        printf("Sorry, negative exponents are not supported.\n");
    }
    else
    {
        int count = 0;
        while (count < expo)
        {
            result *= base; // Multiply base for exponent times
            count++;
        }
        printf("%d raised to the power %d is: %d\n", base, expo, result);
    }

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

// Function to calculate the factorial of a number
void l4p5()
{
    int result = 1, factor;

    printf("\nEnter a non-negative integer to calculate its factorial: ");
    scanf("%d", &factor);

    if (factor < 0)
    {
        printf("Factorials are not defined for negative numbers. Please try again.\n");
    }
    else
    {
        for (int count = 1; count <= factor; count++)
        {
            result *= count; // Multiply to get factorial
        }
        printf("The factorial of %d is: %d\n", factor, result);
    }

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

// Function to check if a number is a palindrome
void l4p6()
{
    int n, rem, original, rev = 0;

    printf("\nEnter an integer to check if it is a palindrome: ");
    scanf("%d", &n);

    original = n; // Store the original number

    while (n != 0)
    {
        rem = n % 10;         // Get the last digit
        rev = rev * 10 + rem; // Append digit to reversed number
        n /= 10;              // Remove last digit
    }

    if (original == rev)
        printf("Yes, %d is a palindrome.\n", original);
    else
        printf("No, %d is not a palindrome.\n", original);

    // Clear input buffer
    while (getchar() != '\n')
        ;
}

int main()
{
    char input[20]; // To hold user input
    printf("Welcome to the Program Menu! Type 'exit' anytime to quit.\n");

    while (1)
    {
        printf("\nChoose a lab to access its programs (type 'exit' to quit):\n");
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
                else if (strcmp(input, "1\n") == 0)
                {
                    l4p1();
                }
                else if (strcmp(input, "2\n") == 0)
                {
                    l4p2();
                }
                else if (strcmp(input, "3\n") == 0)
                {
                    l4p3();
                }
                else if (strcmp(input, "4\n") == 0)
                {
                    l4p4();
                }
                else if (strcmp(input, "5\n") == 0)
                {
                    l4p5();
                }
                else if (strcmp(input, "6\n") == 0)
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
    }

    return 0;
}
