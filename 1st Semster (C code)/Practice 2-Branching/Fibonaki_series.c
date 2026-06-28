#include <stdio.h>

int main() {
    int x =0,y = 1,z =0;
    printf("%d\n", x);
    printf("%d\n", y);
    for(int i=0; i<20; i++){
        z = x+y;
        x=y;
        y=z;
        printf("%d\n", z);
    }
    return 0;
}