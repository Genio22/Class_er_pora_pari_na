#include <stdio.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_ROOMS 40 // 4 rooms per floor, 10 floors max
#define MAX_FLOORS 10
#define MAX_LOGIN_ATTEMPTS 3
#define PEAK_SEASON_START 12 // December
#define PEAK_SEASON_END 2 // February

// Room Structure
typedef struct {
    int roomNumber;
    char type[10];    // "Single" or "Double"
    int floor;        // Floor number
    int isOccupied;   // 0 for available, 1 for occupied
    char view[20];    // "Sea View" or "City View"
    char customerName[50];
    int stayDuration; // Duration of stay in days
    int basePrice;    // Base price for the room (without seasonal or other adjustments)
} Room;

// Prototypes
void initializeRooms();
void addRoom();
void bookRoom();
void displayRooms();
int login();
int isPeakSeason(int month);
int calculatePrice(Room *room, int stayDuration, int month);
void printBillBreakdown(int price, Room *room, int stayDuration, int month);

// Global Variables
Room hotelRooms[MAX_ROOMS];
int roomCount = 0;

// Function to initialize default room details
void initializeRooms() {
    int roomNumber = 101; // Start room numbers from 101
    for (int floor = 1; floor <= MAX_FLOORS-1; floor++) {
        for (int i = 0; i < 4; i++) { // 4 rooms per floor
            hotelRooms[roomCount].roomNumber = roomNumber++;
            hotelRooms[roomCount].floor = floor;
            if (i % 2 == 0) {
                strcpy(hotelRooms[roomCount].type, "Single");
                strcpy(hotelRooms[roomCount].view, "Sea View");
                hotelRooms[roomCount].basePrice = 150; // Base price for Sea View Single
            } else {
                strcpy(hotelRooms[roomCount].type, "Double");
                strcpy(hotelRooms[roomCount].view, "City View");
                hotelRooms[roomCount].basePrice = 120; // Base price for City View Double
            }
            hotelRooms[roomCount].isOccupied = 0; // All rooms are available by default
            roomCount++;
        }
    }
    printf("Default rooms initialized!\n");
}

// Function to check if it is peak season (Winter in Bangladesh: December, January, February)
int isPeakSeason(int month) {
    return (month >= PEAK_SEASON_START || month <= PEAK_SEASON_END);
}

// Function to calculate the price based on the room, stay duration, and season
int calculatePrice(Room *room, int stayDuration, int month) {
    int price = room->basePrice;
    
    // Seasonal pricing: Peak season (winter) increases price
    if (isPeakSeason(month)) {
        price *= 1.2; // Increase by 20% during peak season
    }
    
    // Length of stay pricing
    if (stayDuration > 7) {
        price *= 0.85; // Discount for long stays (7+ days)
    } else if (stayDuration < 3) {
        price *= 1.15; // Higher price for short stays (< 3 days)
    }
    
    // View pricing: Sea View rooms are more expensive
    if (strcmp(room->view, "Sea View") == 0) {
        price *= 1.2; // 20% more expensive for Sea View
    }
    
    return price * stayDuration; // Total price for the entire stay
}

// Function to print a breakdown of the final bill
void printBillBreakdown(int price, Room *room, int stayDuration, int month) {
    int basePrice = room->basePrice;
    int peakSeasonSurcharge = 0;
    int stayAdjustment = 0;
    int seaViewPremium = 0;

    printf("\n--- Final Bill Breakdown ---\n");
    printf("Room Type: %s\n", room->type);
    printf("Room View: %s\n", room->view);
    printf("Stay Duration: %d days\n", stayDuration);
    printf("Base Room Price per night: $%d\n", basePrice);

    // Sea View Premium
    if (strcmp(room->view, "Sea View") == 0) {
        seaViewPremium = 50; // Fixed premium for Sea View rooms
        printf("Sea View Room Premium: +$%d per night\n", seaViewPremium);
        basePrice += seaViewPremium;
    }

    // Peak Season Surcharge
    if (isPeakSeason(month)) {
        peakSeasonSurcharge = (int)(basePrice * 0.2);
        printf("Peak Season Surcharge (20%%): +$%d per night\n", peakSeasonSurcharge);
    }

    // Stay Duration Adjustment
    if (stayDuration > 7) {
        stayAdjustment = -(int)(basePrice * 0.15);
        printf("Long Stay Discount (15%%): -$%d per night\n", -stayAdjustment);
    } else if (stayDuration < 3) {
        stayAdjustment = (int)(basePrice * 0.15);
        printf("Short Stay Surcharge (15%%): +$%d per night\n", stayAdjustment);
    }

    int totalPerNight = basePrice + peakSeasonSurcharge + stayAdjustment;
    int totalPrice = totalPerNight * stayDuration;

    printf("Total Price per Night: $%d\n", totalPerNight);
    printf("Total Charges for %d nights: $%d\n", stayDuration, totalPrice);
    printf("----------------------------\n");
}

// Function to add a new room (only for admin)
void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Room inventory is full!\n");
        return;
    }

    int newRoomNumber;
    printf("Enter room number: ");
    scanf("%d", &newRoomNumber);

    // Check if the room number already exists
    for (int i = 0; i < roomCount; i++) {
        if (hotelRooms[i].roomNumber == newRoomNumber) {
            printf("Room number already exists. Please enter a different one.\n");
            return;
        }
    }

    printf("Enter room type (Single/Double): ");
    scanf("%s", hotelRooms[roomCount].type);

    printf("Enter floor number (1-%d): ", MAX_FLOORS);
    scanf("%d", &hotelRooms[roomCount].floor);
    if (hotelRooms[roomCount].floor < 1 || hotelRooms[roomCount].floor > MAX_FLOORS) {
        printf("Invalid floor number! Room not added.\n");
        return;
    }

    printf("Enter room view (Sea View/City View): ");
    scanf("%s", hotelRooms[roomCount].view);

    printf("Enter base price for the room: ");
    scanf("%d", &hotelRooms[roomCount].basePrice);
    if (hotelRooms[roomCount].basePrice <= 0) {
        printf("Invalid base price! Room not added.\n");
        return;
    }

    hotelRooms[roomCount].isOccupied = 0; // Set room as available
    hotelRooms[roomCount].roomNumber = newRoomNumber;
    roomCount++;

    printf("Room added successfully!\n");
}

// Function to book a room (available for all users)
void bookRoom() {
    char type[10];
    int floor, roomNumber;
    int foundType = 0, foundFloor = 0;
    int stayDuration;

    printf("Enter room type (Single/Double): ");
    scanf("%s", type);

    printf("\nAvailable rooms of type %s:\n", type);
    for (int i = 0; i < roomCount; i++) {
        if (!hotelRooms[i].isOccupied && strcmp(hotelRooms[i].type, type) == 0) {
            printf("Room Number: %d, Floor: %d, View: %s\n", hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].view);
            foundType = 1;
        }
    }

    if (!foundType) {
        printf("No available rooms of type %s!\n", type);
        return;
    }

    printf("\nEnter floor number to narrow down: ");
    scanf("%d", &floor);

    printf("\nAvailable rooms on floor %d:\n", floor);
    for (int i = 0; i < roomCount; i++) {
        if (!hotelRooms[i].isOccupied && strcmp(hotelRooms[i].type, type) == 0 && hotelRooms[i].floor == floor) {
            printf("Room Number: %d, View: %s\n", hotelRooms[i].roomNumber, hotelRooms[i].view);
            foundFloor = 1;
        }
    }

    if (!foundFloor) {
        printf("No available rooms of type %s on floor %d!\n", type, floor);
        return;
    }

    printf("\nEnter room number to select: ");
    scanf("%d", &roomNumber);

    int month;
    printf("Enter current month (1-12): ");
    scanf("%d", &month);

    for (int i = 0; i < roomCount; i++) {
        if (hotelRooms[i].roomNumber == roomNumber && !hotelRooms[i].isOccupied && strcmp(hotelRooms[i].type, type) == 0 && hotelRooms[i].floor == floor) {
            printf("\nYou have selected:\n");
            printf("Room Number: %d, Type: %s, Floor: %d, View: %s\n", 
                   hotelRooms[i].roomNumber, hotelRooms[i].type, hotelRooms[i].floor, hotelRooms[i].view);
            printf("Confirm booking? (1 for Yes, 0 for No): ");
            int confirm;
            scanf("%d", &confirm);

            if (confirm == 1) {
                printf("Enter your name: ");
                scanf("%s", hotelRooms[i].customerName);
                printf("Enter stay duration (in days): ");
                scanf("%d", &stayDuration);
                hotelRooms[i].stayDuration = stayDuration;
                hotelRooms[i].isOccupied = 1; // Mark room as occupied
                
                int price = calculatePrice(&hotelRooms[i], stayDuration, month); // Calculate total price
                printBillBreakdown(price, &hotelRooms[i], stayDuration, month); // Print bill breakdown
            } else {
                printf("Booking cancelled.\n");
            }
            return;
        }
    }

    printf("Invalid room selection!\n");
}

// Function to display all rooms (available for all users)
void displayRooms() {
    printf("Room Inventory:\n");

    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < roomCount; i++) {
        if (!hotelRooms[i].isOccupied) {
            printf("Room Number: %d, Type: %s, Floor: %d, View: %s\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].type, hotelRooms[i].floor, hotelRooms[i].view);
        }
    }

    printf("\nOccupied Rooms:\n");
    for (int i = 0; i < roomCount; i++) {
        if (hotelRooms[i].isOccupied) {
            printf("Room Number: %d, Type: %s, Floor: %d, View: %s, Customer: %s\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].type, hotelRooms[i].floor,
                   hotelRooms[i].view, hotelRooms[i].customerName);
        }
    }
}

// Function to login
int login() {
    int userType;
    char username[50], password[50];
    int attempts = 0;

    // Greet the user and ask for the date at the beginning
    int day, month, year;
    printf("Welcome to the Hotel Booking System!\n");
    printf("Please enter today's date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Today's Date: %02d-%02d-%04d\n", day, month, year);

    printf("Are you a Guest or Admin?\n");
    printf("1. Guest\n");
    printf("2. Admin\n");
    printf("Enter your choice: ");
    scanf("%d", &userType);

    if (userType == 2) {
        // Admin login
        char adminUsername[] = "admin";
        char adminPassword[] = "admin123";

        while (attempts < MAX_LOGIN_ATTEMPTS) {
            printf("Enter admin username: ");
            scanf("%s", username);
            printf("Enter admin password: ");
            scanf("%s", password);

            if (strcmp(username, adminUsername) == 0 && strcmp(password, adminPassword) == 0) {
                printf("Login successful. Welcome, Admin!\n");
                return 1; // Admin login successful
            } else {
                printf("Invalid username or password. Try again.\n");
                attempts++;
            }
        }

        printf("Too many failed login attempts. Access denied.\n");
        return 0; // Admin login failed
    } else if (userType == 1) {
        // Guest login
        printf("You are logged in as a Guest.\n");
        return 2; // Guest login successful
    } else {
        printf("Invalid choice. Please try again.\n");
        return 0; // Invalid choice
    }
}

int main() {
    int choice, stayDuration, month;
    int loggedIn = login();
    
    if (loggedIn == 0) {
        printf("Exiting the system due to failed login.\n");
        return 0; // Exit if login fails
    }

    // Initialize default rooms for the hotel
    initializeRooms();

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Display all rooms\n");
        printf("2. Book a room\n");
        if (loggedIn == 1) {
            printf("3. Add a new room (Admin only)\n");
        }
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms();  // Show available rooms
                break;
            case 2:
                bookRoom();      // Book a room
                break;
            case 3:
                if (loggedIn == 1) {
                    addRoom();  // Add a room (Admin)
                } else {
                    printf("Access denied. Only admins can add rooms.\n");
                }
                break;
            case 4:
                printf("Exiting the system.\n");
                return 0; // Exit the system
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}