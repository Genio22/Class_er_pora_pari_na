


//  array_input()
// {
//     int n,num;
//     printf("Enter the array size: ");
//     scanf("%d", &n);
//     printf("Enter the array: ");
//     scanf("%d", &num);
//     // fulling up array serially 
//     for (int i = n; i >= 0; i--)
//     {
//         arr[i] = num % 10;
//         num /= 10;
//     }

// }

// int check_count(int ar[]){
//     int count = 0;
//     for (int i = n; i >= 0; i--)
//     {
//         arr[i] = num % 10;
//         num /= 10;
//         count++
//     }
//     return count;
    
// }
#include <stdio.h>

int array_input_store(int lookup){
    int n,num;
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    scanf("%d", &num);
    int arr[n];
    for (int i = n; i >= 0; i--)
    {
        arr[i] = num % 10;//Single digite input
        num /= 10;
        // printf("%d\n", arr[i]); // debuging
        
    }
    return arr[lookup];// give output for any value i want only i have tell the position
}

int main(){
    int a,max = -9999999;
    
    for (int i = 100; i >= 0; i--)
    {
        a = array_input_store(i);
        if (a > max){
            max = a;
        }
        
        // printf("%d\n", a); // debuging
        
    }
    // int n,num;
    // printf("Enter the array size: ");
    // scanf("%d", &n);
    // printf("Enter the array: ");
    // scanf("%d", &num);
    // int arr[n];
    // // fulling up array serially 
    // for (int i = n; i >= 0; i--)
    // {
    //     arr[i] = num % 10;//Single digite input
    //     num /= 10;
    //     // printf("%d\n", arr[i]); // debuging
    //     if (arr[i] > max){
    //         max = arr[i];
    //     }
    // }
    printf("Max value among the array: %d",max);

    return 0;
}