#include <stdio.h>

int main() {
    int x,y;
    printf("Enter a integer: ");
    scanf("%d", &x);


    if ((x%5)==0 || (x%10)==0) {        
        if ((x%10)==0) { 
            if ((x%5)==0) {
                if ((x%5)==0 || (x%10)==0){
                    printf("Divisible by both 5 and 10");
                }
                else{
                    printf("Divisible only by 5");
                } 
            }
            else{
                printf("Divisible only by 10");
            }
        }
        else{
        printf("Divisible by both 5 and 10");
        }
    }
    else {
        printf("You are badly fucked up\n");
    }
    return 0;
}
