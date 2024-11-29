#include <stdio.h>


int find_max(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}


int find_min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    int num1, num2, num3;


    printf("Enter three numbers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);


    int max = find_max(num1, num2, num3);
    int min = find_min(num1, num2, num3);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
