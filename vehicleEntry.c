#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <winbase.h>
#include <windows.h>
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
        char vehInTime[20];
    } readVehicleNum;

    FILE *vehicleEntryPointer;
    vehicleEntryPointer = fopen("vehicle-entry.txt", "a+");
    printf("Vehicle Number : ");
    scanf("%s", vehNum);
    strcpy(readVehicleNum.vehicleNum, vehNum);
    fputs(readVehicleNum.vehicleNum, vehicleEntryPointer);
    // fputs(, vehicleEntryPointer);
    fprintf(vehicleEntryPointer, "Vehicle Number : %s ", readVehicleNum.vehicleNum);

    // time_t seconds;
    // seconds = time(NULL);
    // readVehicleNum.vehInTime = &seconds;
    // fprintf(vehicleEntryPointer, "\n%ld\n\n", readVehicleNum.vehInTime);

    struct tm *local;
    time_t myTime = time(NULL);
    local = localtime(&myTime);
   
    fprintf(vehicleEntryPointer, "\nIn Time : %s\n\n", asctime(local));
    // fputs(asctime(local), vehicleEntryPointer);

    fclose(vehicleEntryPointer);
    // printf("Time : %ld\n", &seconds);
}