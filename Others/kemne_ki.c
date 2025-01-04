#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_FLOORS 5
#define PEAK_SEASON_START 11
#define PEAK_SEASON_END 2

// Room structure
typedef struct {
    int roomNumber;
    int floor;
    char type[20];
    char view[20];
    int basePrice;
    int isOccupied;
} Room;

// Global variables
Room hotelRooms[MAX_ROOMS];
int roomCount = 0;

// Function prototypes
void initializeRooms();
void displayRooms();
void bookRoom();
void printBillBreakdown(Room room, int duration);
int calculatePrice(Room room, int duration, int peakSeason);
int isPeakSeason();

int main() {
    int choice;
    initializeRooms();

    do {
        printf("\n--- Sea Villa Hotel Management System ---\n");
        printf("1. Display Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                printf("Thank you for using the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void initializeRooms() {
    int roomNumber = 100;
    for (int floor = 1; floor <= MAX_FLOORS; floor++) {
        for (int i = 0; i < 4; i++) {
            hotelRooms[roomCount].roomNumber = roomNumber++;
            hotelRooms[roomCount].floor = floor;
            if (i % 2 == 0) {
                strcpy(hotelRooms[roomCount].type, "Single");
                strcpy(hotelRooms[roomCount].view, "Sea View");
                hotelRooms[roomCount].basePrice = 150;
            } else {
                strcpy(hotelRooms[roomCount].type, "Double");
                strcpy(hotelRooms[roomCount].view, "City View");
                hotelRooms[roomCount].basePrice = 120;
            }
            hotelRooms[roomCount].isOccupied = 0;
            roomCount++;
        }
    }
    printf("Default rooms initialized!\n");
}

void displayRooms() {
    printf("\n--- Available Rooms ---\n");
    for (int i = 0; i < roomCount; i++) {
        if (!hotelRooms[i].isOccupied) {
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, Base Price: $%d\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view,
                   hotelRooms[i].basePrice);
        }
    }
}

void bookRoom() {
    int roomNumber, duration;
    printf("\nEnter the room number to book: ");
    scanf("%d", &roomNumber);

    Room *selectedRoom = NULL;
    for (int i = 0; i < roomCount; i++) {
        if (hotelRooms[i].roomNumber == roomNumber) {
            selectedRoom = &hotelRooms[i];
            break;
        }
    }

    if (selectedRoom == NULL || selectedRoom->isOccupied) {
        printf("Room not available or invalid room number.\n");
        return;
    }

    printf("Enter the duration of stay (in days): ");
    scanf("%d", &duration);

    int peakSeason = isPeakSeason();
    int totalPrice = calculatePrice(*selectedRoom, duration, peakSeason);
    printf("\nBooking successful!\n");
    printBillBreakdown(*selectedRoom, duration);

    selectedRoom->isOccupied = 1;
}

void printBillBreakdown(Room room, int duration) {
    int peakSeason = isPeakSeason();
    int seaViewPremium = (strcmp(room.view, "Sea View") == 0) ? 20 : 0;
    int peakSeasonSurcharge = peakSeason ? 50 : 0;
    int stayAdjustment = (duration > 3) ? -10 : 0;
    int totalPrice = calculatePrice(room, duration, peakSeason);

    printf("\n--- Bill Breakdown ---\n");
    printf("Base Price (per night): $%d\n", room.basePrice);
    printf("Sea View Premium (per night): $%d\n", seaViewPremium);
    printf("Peak Season Surcharge (per night): $%d\n", peakSeasonSurcharge);
    printf("Stay Adjustment (per night): $%d\n", stayAdjustment);
    printf("Total Price: $%d\n", totalPrice);
}

int calculatePrice(Room room, int duration, int peakSeason) {
    int seaViewPremium = (strcmp(room.view, "Sea View") == 0) ? 20 : 0;
    int peakSeasonSurcharge = peakSeason ? 50 : 0;
    int stayAdjustment = (duration > 3) ? -10 : 0;

    int nightlyPrice = room.basePrice + seaViewPremium + peakSeasonSurcharge + stayAdjustment;
    return nightlyPrice * duration;
}

int isPeakSeason() {
    int month;
    printf("Enter the current month (1-12): ");
    scanf("%d", &month);
    return (month >= PEAK_SEASON_START || month <= PEAK_SEASON_END);
}
