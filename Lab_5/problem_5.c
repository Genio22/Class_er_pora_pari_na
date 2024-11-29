#include <stdio.h>

int a, b, n, result =1 ;

int power(int a, int b){
    for (int i=1;i<=b; i++){
        result *= a;
    }
    return result;
}
int main(){
    scanf("%d %d", &a, &b);
    int final_result = power(a,b);
    printf("%d", final_result);
    return 0;
}
