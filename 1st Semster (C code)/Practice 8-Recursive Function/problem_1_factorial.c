/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

int find_factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n*find_factorial(n-1);
    }
}

int main()
{
    int n, factorial;
    printf("Enter the number of you want to find factorial: ");
    scanf("%d", &n);
    factorial = find_factorial(n);
    printf("%dth -> %d", n, factorial);
    return 0;
}

// By sAhAf🙂