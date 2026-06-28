// Student Honors and Distinction:
#include <stdio.h>

void main(){
    int score;
    printf ("Enter your score: ");
    scanf ("%d", &score);

    if (score>=50) {
        if (69<score) {
            if (84<score){
                if (score>=85){
                    printf("Distinction");
                }
            }
            else{
                printf ("First Class");
            }
        }
        else{
            printf("Second Class");
        }
    }
    else {
        printf ("Fail");
    }   
    // return 0;
}