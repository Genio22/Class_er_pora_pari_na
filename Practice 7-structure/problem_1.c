/* Write a program to define a structure for a bank account, which includes the account
holder’s name, account number, balance, and account type. Implement functions to deposit
and withdraw money, ensuring that the balance cannot be negative. Handle errors for
insufficient balance during withdrawals.
▪ Sample Input:
    Account Holder: John Doe, Account Number: 12345, Initial Balance: 1000, Account
    Type: Savings
    Deposit: 500, Withdraw: 200, Withdraw: 1500
▪ Sample Output:
    Account Details:
    Name: John Doe
    Account Number: 12345
    Account Type: Savings
    Balance: 1300
    Error: Insufficient Balance for withdrawal of 1500 */
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char name[100];
    int account_number;
    int balance;
    char a_type[50];
} bank_account;

bank_account ba;

void deposit(int in_money)
{
    if (in_money < 0)
    {
        printf("Invalid input\n");
    }
    else
    {
        ba.balance += in_money;
        printf("New Balance: %d\n", ba.balance);
    }
}

void withdraw(int want_money)
{
    if (ba.balance < want_money)
    {
        printf("Insufficient Balance for withdrawal of %d\n", want_money);
    }
    else
    {
        ba.balance -= want_money;
        printf("New Balance: %d\n", ba.balance);
    }
}

void print_account_details()
{
    printf("\nAccount Details:\n");
    printf("Name: %s\n", ba.name);
    printf("Account Number: %d\n", ba.account_number);
    printf("Account Type: %s\n", ba.a_type);
    printf("Balance: %d\n", ba.balance);
}

int main()
{
    int in_money = 0, want_money = 0, choice = 0;
    // intial details
    printf("\nAccount Details:\n");
    printf("Name: ");
    scanf("%[^\n]s", ba.name);

    printf("Account Number: ");
    scanf("%d", &ba.account_number);

    printf("Balance: ");
    scanf("%d", &ba.balance);
    getchar();

    printf("Account Type: ");
    scanf("%[^\n]s", ba.a_type);

    print_account_details();

    while (choice != 5)
    {
        printf("\n\nMain Menu\n");
        printf("Deposit -> 1\n");
        printf("Withdraw -> 2\n");
        printf("Exit -> 5\n");
        printf("-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Deposit: ");
            scanf("%d", &in_money);
            deposit(in_money);
            break;
        case 2:
            printf("Withdraw: ");
            scanf("%d", &want_money);
            withdraw(want_money);
            break;
        case 5:
            print_account_details();
            return 0;
        default:
            break;
        }
    }

    return 0;
}

// By sAhAf🙂