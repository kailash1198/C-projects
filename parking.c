#include "vehicleEntry.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    int goHomeKey;
    int optionSelect;
homePage:
    system("CLS");
    printf("\t\tABC PARKING CENTERS, BANGALORE\n\n\n\n");
    printf("Please enter what you want :\n\n1. Vehicle In\t\t2. Vehicle Out\n3. Search Vehicles\t4. Vehicles Report\n\n\n\n\n");
    printf("Your Option : ");
    scanf("%d", &optionSelect);

    if (optionSelect == 1)
    {
        vehicleIn();
        printf("\n\nPress any key to go Home Page\n\n");
        scanf("%d", &goHomeKey);
        if (goHomeKey !=NULL)
        {
            goto homePage;
        }
    }
}