/*Write a program in C to read n number of values in an array and display them in reverse order.*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the memory for array: ");
    scanf("%d", &n);
    int num_order[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &num_order[i]);
    }
    int nn = n-1;
    for (int i=nn; i>=0; i--)
    {
        printf("the number in reverse order %d \n", num_order[i]);
    }
    return 0;
}





// By sAhAf🙂