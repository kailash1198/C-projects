#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <winuser.h>

void vehicleIn()
{
    char vehNum[15];
     int userClickBtn;
    system("CLS");
    printf("\n\t\tVehicle Entry Dashboard\n\n\n");

    struct vehicleInEntry
    {

        char vehicleNum[15];
    } readVehicleNum;

    FILE *vehicleEntryPointer;
    vehicleEntryPointer = fopen("vehicle-entry.txt", "w");
    printf("Vehicle Number : ");
    scanf("%s", vehNum);
    strcpy(readVehicleNum.vehicleNum, vehNum);
    // printf("Vehicle num = %s", readVehicleNum.vehicleNum);
    // fprintf(vehicleEntryPointer, vehNum);
    fputs(readVehicleNum.vehicleNum, vehicleEntryPointer);
    fclose(vehicleEntryPointer);
    printf("\n\nPress any key to go Home Page\n\n");
    
    
   
    
}