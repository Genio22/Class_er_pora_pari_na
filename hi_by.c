#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 50

// Room structure
typedef struct {
    int roomNumber;
    char type[10]; // "single" or "double"
    char status[10]; // "available" or "occupied"
    char customerName[50];
    int checkInDay;
    int checkOutDay;
    int pricePerDay;
} Room;

// Customer structure
typedef struct {
    char name[50];
    int loyaltyPoints;
} Customer;

Room rooms[MAX_ROOMS];
Customer customers[MAX_CUSTOMERS];
int roomCount = 0;
int customerCount = 0;

// Function prototypes
void addRoom();
void bookRoom();
void checkOutRoom();
void searchRoomByType();
void displayAllRooms();
void initializeDefaultRooms();
void manageLoyaltyPoints(const char *customerName, int points);
void displayLoyaltyPoints(const char *customerName);
void addAdditionalServices();
void dynamicPricing();
void advancedSearchFilters();

int main() {
    int choice;

    // Initialize default rooms
    initializeDefaultRooms();

    do {
        printf("\nHotel Room Booking System\n");
        printf("1. Add Room\n");
        printf("2. Book Room\n");
        printf("3. Check Out Room\n");
        printf("4. Search Room by Type\n");
        printf("5. Display All Rooms\n");
        printf("6. Add Additional Services\n");
        printf("7. Display Loyalty Points\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                checkOutRoom();
                break;
            case 4:
                searchRoomByType();
                break;
            case 5:
                displayAllRooms();
                break;
            case 6:
                addAdditionalServices();
                break;
            case 7: {
                char name[50];
                printf("Enter customer name to view loyalty points: ");
                scanf("%s", name);
                displayLoyaltyPoints(name);
                break;
            }
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

// Add default rooms to inventory
void initializeDefaultRooms() {
    Room defaultRooms[] = {
        {101, "single", "available", "", 0, 0, 100},
        {102, "double", "available", "", 0, 0, 150},
        {103, "single", "available", "", 0, 0, 100},
        {104, "double", "available", "", 0, 0, 150},
        {105, "single", "available", "", 0, 0, 100}
    };

    int defaultRoomCount = sizeof(defaultRooms) / sizeof(defaultRooms[0]);
    for (int i = 0; i < defaultRoomCount; i++) {
        rooms[roomCount++] = defaultRooms[i];
    }
}

// Add a room to inventory
void addRoom() {
    if (roomCount >= MAX_ROOMS) {
        printf("Room inventory is full!\n");
        return;
    }

    Room newRoom;
    printf("Enter room number: ");
    scanf("%d", &newRoom.roomNumber);
    printf("Enter room type (single/double): ");
    scanf("%s", newRoom.type);
    printf("Enter price per day: ");
    scanf("%d", &newRoom.pricePerDay);
    strcpy(newRoom.status, "available"); // Default status is available
    newRoom.customerName[0] = '\0';
    newRoom.checkInDay = 0;
    newRoom.checkOutDay = 0;

    rooms[roomCount++] = newRoom;
    printf("Room added successfully!\n");
}

// Book a room
void bookRoom() {
    int roomNumber;

    printf("Available rooms:\n");
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].status, "available") == 0) {
            printf("Room Number: %d, Type: %s, Price: $%d\n", rooms[i].roomNumber, rooms[i].type, rooms[i].pricePerDay);
        }
    }

    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (strcmp(rooms[i].status, "available") == 0) {
                printf("Enter customer name: ");
                scanf("%s", rooms[i].customerName);
                printf("Enter check-in day: ");
                scanf("%d", &rooms[i].checkInDay);
                printf("Enter check-out day: ");
                scanf("%d", &rooms[i].checkOutDay);

                strcpy(rooms[i].status, "occupied");
                manageLoyaltyPoints(rooms[i].customerName, 10); // Add loyalty points
                printf("Room booked successfully!\n");
                return;
            } else {
                printf("Room is already occupied!\n");
                return;
            }
        }
    }

    printf("Room not found!\n");
}

// Check out a room
void checkOutRoom() {
    int roomNumber;
    printf("Enter room number to check out: ");
    scanf("%d", &roomNumber);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (strcmp(rooms[i].status, "occupied") == 0) {
                int duration = rooms[i].checkOutDay - rooms[i].checkInDay;
                if (duration < 0) duration = 0; // Handle invalid duration
                int totalCharge = duration * rooms[i].pricePerDay;
                printf("Customer %s checked out.\n", rooms[i].customerName);
                printf("Total charge for %d days: $%d\n", duration, totalCharge);

                strcpy(rooms[i].status, "available");
                rooms[i].customerName[0] = '\0';
                rooms[i].checkInDay = 0;
                rooms[i].checkOutDay = 0;
                printf("Room checked out successfully!\n");
                return;
            } else {
                printf("Room is already available!\n");
                return;
            }
        }
    }

    printf("Room not found!\n");
}

// Manage loyalty points
void manageLoyaltyPoints(const char *customerName, int points) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, customerName) == 0) {
            customers[i].loyaltyPoints += points;
            return;
        }
    }

    strcpy(customers[customerCount].name, customerName);
    customers[customerCount].loyaltyPoints = points;
    customerCount++;
}

// Display loyalty points
void displayLoyaltyPoints(const char *customerName) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, customerName) == 0) {
            printf("Customer %s has %d loyalty points.\n", customerName, customers[i].loyaltyPoints);
            return;
        }
    }

    printf("Customer %s not found!\n", customerName);
}

// Add additional services
void addAdditionalServices() {
    printf("Feature coming soon!\n");
}

// Search rooms by type
void searchRoomByType() {
    char type[10];
    printf("Enter room type to search (single/double): ");
    scanf("%s", type);

    printf("Available rooms of type %s:\n", type);
    for (int i = 0; i < roomCount; i++) {
        if (strcmp(rooms[i].type, type) == 0 && strcmp(rooms[i].status, "available") == 0) {
            printf("Room Number: %d, Price: $%d\n", rooms[i].roomNumber, rooms[i].pricePerDay);
        }
    }
}

// Display all rooms
void displayAllRooms() {
    printf("\nRoom Inventory:\n");
    for (int i = 0; i < roomCount; i++) {
        printf("Room Number: %d, Type: %s, Status: %s, Price: $%d\n",
               rooms[i].roomNumber, rooms[i].type, rooms[i].status, rooms[i].pricePerDay);
    }
}
