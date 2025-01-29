/*Given an array of exam scores, use pointers to find the top 3 scores and their positions in the
array.*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int a[] = {4,67,89,90,20};
    int *pa, first = 0, second = 0, third = 0;
    pa = &a[0];
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        if (*(pa+i)>first){
            third = second;
            second = first;
            first = *(pa+i);
        }
        else if(*(pa+i)>second){
            third = second;
            second = *(pa+i);
        }
        else if(*(pa+i)>third){
            third = *(pa+i);
        }
    }
    printf("Top 3 scores: %d, %d, %d\n", first, second, third);
        
    return 0;
}

// By sAhAf🙂