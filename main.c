#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 5
#define MAX_ROWS 10
#define MAX_COLS 10
#define PARKING_RATE_PER_HOUR 10

// Data structure to represent parking lot
bool parking_lot[MAX_FLOORS][MAX_ROWS][MAX_COLS];
int available_spots = MAX_FLOORS * MAX_ROWS * MAX_COLS;
float total_revenue = 0;

// Function to initialize parking lot
void initialize_parking_lot() {
    for (int i = 0; i < MAX_FLOORS; i++) {
        for (int j = 0; j < MAX_ROWS; j++) {
            for (int k = 0; k < MAX_COLS; k++) {
                parking_lot[i][j][k] = true; // All spots initially available
            }
        }
    }
}

// Function to find available spot
bool find_available_spot(int *floor, int *row, int *col) {
    for (int i = 0; i < MAX_FLOORS; i++) {
        for (int j = 0; j < MAX_ROWS; j++) {
            for (int k = 0; k < MAX_COLS; k++) {
                if (parking_lot[i][j][k]) {
                    *floor = i;
                    *row = j;
                    *col = k;
                    return true;
                }
            }
        }
    }
    return false; // No available spot found
}

// Function for vehicle entry
void vehicle_entry() {
    int floor, row, col;
    if (find_available_spot(&floor, &row, &col)) {
        parking_lot[floor][row][col] = false;
        available_spots--;
        printf("Vehicle parked at Floor %d, Row %d, Spot %d\n", floor+1, row+1, col+1);
    } else {
        printf("Sorry, parking lot is full.\n");
    }
}

// Function for vehicle exit
void vehicle_exit() {
    int floor, row, col;
    printf("Enter floor, row, and column of the parked vehicle: ");
    scanf("%d %d %d", &floor, &row, &col);

    if (floor >= 1 && floor <= MAX_FLOORS && row >= 1 && row <= MAX_ROWS && col >= 1 && col <= MAX_COLS) {
        if (!parking_lot[floor-1][row-1][col-1]) {
            parking_lot[floor-1][row-1][col-1] = true;
            available_spots++;
            float parking_fee = PARKING_RATE_PER_HOUR; // Assuming flat rate per hour
            total_revenue += parking_fee;
            printf("Vehicle exited from Floor %d, Row %d, Spot %d. Parking fee: $%.2f\n", floor, row, col, parking_fee);
        } else {
            printf("Error: No vehicle found at specified spot.\n");
        }
    } else {
        printf("Error: Invalid floor, row, or column number.\n");
    }
}

// Function to display available spots
void display_available_spots() {
    printf("Available spots: %d\n", available_spots);
}

// Function to display total revenue
void display_total_revenue() {
    printf("Total revenue: $%.2f\n", total_revenue);
}

int main() {
    initialize_parking_lot();

    int choice;
    do {
        printf("\nParking Management System\n");
        printf("1. Vehicle Entry\n");
        printf("2. Vehicle Exit\n");
        printf("3. Display Available Spots\n");
        printf("4. Display Total Revenue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vehicle_entry();
                break;
            case 2:
                vehicle_exit();
                break;
            case 3:
                display_available_spots();
                break;
            case 4:
                display_total_revenue();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
