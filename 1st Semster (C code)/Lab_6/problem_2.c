/*Write a C program to count total number of even and odd elements in an array..*/
#include <stdio.h>


int main(){
    int n, sum_even=0, sum_odd = 0, total_count;
    printf("Enter the memory for array: ");
    scanf("%d", &n);
    int num_order[n];
    for (int i=0; i<n; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &num_order[i]);
        if ((num_order[i] % 2) == 0){
            sum_even ++;
    }
        else if ((num_order[i] % 2) != 0){
            sum_odd ++;
        }
    }
    printf("Sum of even %d and sum of odd %d\n", sum_even, sum_odd);
    total_count = sum_even + sum_odd;
    printf("Total count -> %d", total_count);
    return 0;
}





// By sAhAf🙂
