/*4. Check if a Given Number Is an Armstrong Number
An Armstrong number is a number that is equal to the sum of its digits raised to the power of the
number of digits. For example, 153 = 1^3 + 5^3 + 3^3. Input a number, calculate the sum
of its digit powers, and check if it equals the original number.*/
#include <stdio.h>
#include <math.h>

int main() {
    int num, divide = 1, or_num, sum = 0, cube;

    // Prompt the user to input a number
    printf("Enter a number to check Armstrong Number: ");
    scanf("%d", &num);

    // Preserve the original number for comparison
    or_num = num;

    // Loop to extract each digit, calculate its cube, and add to the sum
    while (divide != 0) {
        divide = or_num % 10;        // Get the last digit
        or_num = or_num / 10;        // Remove the last digit
        cube = divide * divide * divide;  // Calculate the cube
        sum += cube;                 // Add the cube to the sum
    }

    // Check if the sum equals the original number
    (sum == num) ? printf("%d is an Armstrong Number.\n", num) : printf("%d is not an Armstrong Number.\n", num);
    // if (sum == num) {
    //     printf("%d is an Armstrong Number.\n", num);
    // } else {
    //     printf("%d is not an Armstrong Number.\n", num);
    // }

    return 0;
}
