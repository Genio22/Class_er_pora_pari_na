/*Temperature Check: Prompt the user to enter a temperature in Celsius and
print "Above freezing" if the temperature is above 0°C, otherwise print "At
or below freezing."*/
#include <stdio.h>

int main() {
    int x;
    printf("Enter a Celsius: \n");
    scanf("%d", &x);

    if (x>0) {
        printf("Above freezing\n");
    }
    else {
        printf("Below freezing\n");
    }
    return 0;
}
