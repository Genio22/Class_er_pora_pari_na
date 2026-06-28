#include <stdio.h>
#include <string.h>
void Nid_output()
{
    char NID[18];
    printf("Enter your 17 digit NID number. If it's less than 17 digits, add zeros at the beginning.\n");
    printf("Enter Your NID number: ");
    scanf("%s", &NID);

    while (1)
    {   
        if (strlen(NID) != 17)
        {
            printf("Wrong entry. Please try again.\n");
            printf("Enter Your NID number: ");
            scanf("%s", &NID);
        }
        else{
            printf("Nid number: %s", NID);
            break;
        }
    }
    
}