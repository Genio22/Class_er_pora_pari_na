#include <stdio.h>

int start, end, count =0;


int divisible_count(int start, int end){
    for (int i= start; i<=end ;i++){
        if (i % 5 == 0 && i % 7 == 0 ){
            count++;
        }
    }
    return count;
}



int main(){
    scanf("%d %d", &start, &end);
    int final_result = divisible_count(start, end);
    printf("%d", final_result);
    return 0;
}
