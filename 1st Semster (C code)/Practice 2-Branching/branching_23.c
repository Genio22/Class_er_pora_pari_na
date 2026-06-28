#include <stdio.h>

void main(){
    int num1 = 0, num2 = 0, result;
    char op;
    // printf("Enter the opration you want to perform(+,-,*,/): ");
    // scanf("%c", &op);
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);
    // with space before %c to handle newline character
    printf("Enter the opration you want to perform(+,-,*,/): ");
    scanf(" %c", &op);

    switch (op){
        case '+':
            printf("Result: %d", result = num1+num2);
            break;
        case '-':
            printf("Result: %d", result = num1-num2);
            break;
        case '*':
            printf("Result: %d", result = num1 * num2);
            break;
        case '/':
            if (num2!=0){
                printf("Result: %d", result = num1/num2);
                break;
            }
            else{
                printf("your are divideing it by zero.  \nXX It is not allowed XX");
            }
            
        case '%':
            printf("Result: %d", result = num1%num2);
            break;
        default:
            printf("Invalid operator.\n");
            break;

    }
} 