/*Problem 6
The greatest common divisor (GCD) of two integers is the largest integer that evenly divides each of
the two numbers. Write a function gcd thatreturnsthe greatest common divisor oftwo integers.
example:Enter a number: 36
Enter another number: 60
The GCD of 36 & 60 is 12
*/
#include <stdio.h>
#include <stdlib.h> // for abs()

int a, b, result = 1;

int GCD(int a, int b)
{
    a = abs(a); // to avoid negative number
    b = abs(b);
    for (int i = 1; i <= (a < b ? a : b); i++)
    {
        // main gcd ai khane check hoy
        if ((a % i == 0) && (b % i == 0))
        {
            result = i;
        }
    }
    return result;
}

int main()
{
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);

    // handling error when number are zero
    if (a == 0 && b == 0)
    {
        printf("GCD is undefined for both numbers being zero.\n");
    }
    else
    {
        printf("The GCD of %d & %d is %d", a, b, GCD(a, b));
    }
    return 0;
}




// By AhNaF🙂