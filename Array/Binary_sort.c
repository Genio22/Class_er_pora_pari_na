#include <stdio.h>
int num, n, single_digite;
int a;
int arr[1000];
// input array and get answer
void array_input()
{
    for (int i = n; i >= 0; i--)
    {
        arr[i] = num % 10;
        num /= 10;
    }
}

int Binary_sort(int target)
{
    int first = arr[0], last = arr[n - 1];

    // Funtion
    while (first <= last)
    {
        int mid_value = (first + last) / 2;
        if (target == arr[mid_value])
        {
            // printf("Target is at %d number array", mid_value);
            return mid_value;
        }
        else if (target > arr[mid_value])
        {
            first = mid_value + 1;
        }
        else
        {
            last = mid_value - 1;
        }
    }
    return -1;
}

int main()
{
    int target, first, last;
    int indx = -1;
    // input
    printf("Enter the array Size: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    scanf("%d", &num);
    printf("Enter the target num: ");
    scanf("%d", &target);

    array_input();

    int check = Binary_sort(target);
    if (check == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("Target %d found at array location %d position.", target, check);
    }

    return 0;
}