/*Write a C program to merge two arrays third array.*/

#include <stdio.h>

int countDigits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int main()
{
    int num1, num2;
    printf("Enter the number for the first array: ");
    scanf("%d", &num1);
    int n1 = countDigits(num1);
    int arr1[n1];
    for (int i = n1 - 1; i >= 0; i--)
    {
        arr1[i] = num1 % 10;
        num1 /= 10;
    }
    printf("Enter the number for the second array: ");
    scanf("%d", &num2);

    int n2 = countDigits(num2);
    int arr2[n2];

    for (int i = n2 - 1; i >= 0; i--)
    {
        arr2[i] = num2 % 10;
        num2 /= 10;
    }
    int mergedArray[n1 + n2];
    for (int i = 0; i < n1; i++)
    {
        mergedArray[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        mergedArray[n1 + i] = arr2[i];
    }

    printf("Merged Array: ");
    for (int i = 0; i < (n1 + n2); i++)
    {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}








// By sAhAf🙂