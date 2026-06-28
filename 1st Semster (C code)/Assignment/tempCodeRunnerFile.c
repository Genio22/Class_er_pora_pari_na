/*4. Check if a Given Number Is an Armstrong Number
An Armstrong number is a number that is equal to the sum of its digits raised to the power of the
number of digits. For example, 153 = 1^3 + 5^3 + 3^3. Input a number, calculate the sum
of its digit powers, and check if it equals the original number.*/
#include <stdio.h>
#include <math.h>

int digit_calculate(int num){
    int count = 0;
    while(num != 0){        
        num /= 10;
        count++;
    }
    return count;
}

int power_calculation(int num){
    int sum = 0, single_digit;
    int b = digit_calculate(num); 
    
    while (num != 0){        
        single_digit = num % 10;       
        num /= 10;
        sum += pow(single_digit, b);
    }
    return sum;
}

int main() {
    int num, or_num;
    int total;
    printf("Enter a number to check Armstrong Number: ");
    scanf("%d", &num);
    // Bug Test
    int x = digit_calculate(num);
    printf("%d\n", x);
    int y = power_calculation(num);
    printf("%d\n", y);
    // or_num = num;
    total = power_calculation(num) ;

    (total == num) ? printf("%d is an Armstrong Number.\n", num) : printf("%d is not an Armstrong Number.\n", num);

    return 0;
}
