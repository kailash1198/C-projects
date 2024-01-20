#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vehicleEntry.c"

int main(void){
    int optionSelect;
    system("CLS");
    printf("\t\tABC PARKING CENTERS, BANGALORE\n\n\n\n");
    printf("Please enter what you want :\n\n1. Vehicle In\t\t2. Vehicle Out\n3. Search Vehicles\t4. Vehicles Report\n\n\n\n\n");
    printf("Your Option : ");
    scanf("%d", &optionSelect);

    if(optionSelect==1){
        vehicleIn();
    }

}