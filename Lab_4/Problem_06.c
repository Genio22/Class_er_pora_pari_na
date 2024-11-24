/*Write a program in C to check whether a number is a palindrome or not.
Test Data :
Input a number: 121
Expected Output :
121 is a palindrome number.*/
#include <stdio.h>
int main()
{
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
    return 0;
}

// By sAhAf