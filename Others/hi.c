#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ROOMS 100
#define MAX_FLOORS 10

// Room structure
typedef struct
{
    int roomNumber;
    int floor;
    char type[20];
    char view[20];
    char ac_type[20];
    int basePrice;
    int isOccupied;
} Room;

// Global variables
Room hotelRooms[MAX_ROOMS];
int roomCount = 0;

// Function prototypes
void showMenu();
void initializeRooms(int floors, int roomsPerFloor);
void displayRooms();
void addRoom();
void saveRoomsToFile();
void loadRoomsFromFile();
void bookRoom();
void trimNewline(char *str);
int main()
{
    int choice = 0;
    int floors, roomsPerFloor;

    // Load existing rooms from the file at the start
    loadRoomsFromFile();

    // Asking for floor and room count
    printf("Enter the number of floors: ");
    scanf("%d", &floors);
    printf("Enter the number of rooms per floor: ");
    scanf("%d", &roomsPerFloor);

    // Initialize rooms with random data
    initializeRooms(floors, roomsPerFloor);

    // Save the newly generated room data to the file
    saveRoomsToFile();

    while (choice != 4)
    {
        showMenu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            displayRooms();
            break;
        case 2:
            addRoom();
            break;
        case 3:
            bookRoom();
            break;
        case 4:
            saveRoomsToFile(); // Save rooms to file before exiting
            printf("Exiting the system. Data saved!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void showMenu()
{
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Book a Room\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void initializeRooms(int floors, int roomsPerFloor)
{
    const char *roomTypes[] = {"Single", "Double"};
    const char *views[] = {"Sea", "City"};
    const char *acTypes[] = {"AC", "Non AC"};
    int basePrices[] = {1350, 2000};

    srand(time(NULL));

    // Initialize rooms with random data based on the user input for floors and rooms per floor
    for (int floor = 1; floor <= floors; floor++)
    {
        for (int i = 0; i < roomsPerFloor; i++)
        {
            hotelRooms[roomCount].roomNumber = floor * 100 + i; // Room number format: 100, 101, 102...
            hotelRooms[roomCount].floor = floor;
            strcpy(hotelRooms[roomCount].type, roomTypes[rand() % 2]);
            strcpy(hotelRooms[roomCount].view, views[rand() % 2]);
            strcpy(hotelRooms[roomCount].ac_type, acTypes[rand() % 2]);
            hotelRooms[roomCount].basePrice = basePrices[rand() % 2];
            hotelRooms[roomCount].isOccupied = 0; // rand() % 2;  // Randomly occupied or not
            roomCount++;
        }
    }
    printf("Rooms initialized with random data.\n");
}

1                                                                                                                                                                                       printf("\nRoom Data:\n");
    printf("------------------------------------------------------------\n");
    printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-8s | %-6d |\n",
               hotelRooms[i].roomNumber,
               hotelRooms[i].floor,
               hotelRooms[i].type,
               hotelRooms[i].view,
               hotelRooms[i].ac_type,
               hotelRooms[i].isOccupied ? "Yes" : "No",
               hotelRooms[i].basePrice);
    }

    printf("------------------------------------------------------------\n");
}

void addRoom()
{
    int roomNumber, floor, basePrice, isOccupied;
    char type[20], view[20], ac_type[20];

    if (roomCount < MAX_ROOMS)
    {
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);
        printf("Enter Floor: ");
        scanf("%d", &floor);
        printf("Enter Room Type (e.g., Single, Double): ");
        scanf("%s", type);
        printf("Enter View (e.g., Sea, City): ");
        scanf("%s", view);
        printf("Enter AC type (e.g., AC, Non AC): ");
        scanf("%s", ac_type);
        printf("Enter Base Price: ");
        scanf("%d", &basePrice);
        printf("Is the room occupied? (1 for Yes, 0 for No): ");
        scanf("%d", &isOccupied);

        hotelRooms[roomCount].roomNumber = roomNumber;
        hotelRooms[roomCount].floor = floor;
        hotelRooms[roomCount].basePrice = basePrice;
        hotelRooms[roomCount].isOccupied = isOccupied;
        strcpy(hotelRooms[roomCount].type, type);
        strcpy(hotelRooms[roomCount].view, view);
        strcpy(hotelRooms[roomCount].ac_type, ac_type);

        roomCount++;
        printf("\nRoom added successfully.\n");

        // Save the updated rooms to file after adding a room
        saveRoomsToFile();
    }
    else
    {
        printf("Sorry, no more room available! We are fully booked! Please check back later.\n");
    }
}

// Helper function to trim newline characters from fgets
void trimNewline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

void bookRoom()
{
    char selectedType[50];
    char selectedView[50];
    char selectedACType[50];
    int selectedRoomNumber;
    int foundRooms[MAX_ROOMS];
    int foundCount = 0;

    // Step 1: Filter by Room Type
    printf("\nAvailable Room Types: Single, Double\n");
    printf("Enter your preferred room type: ");
    fgets(selectedType, sizeof(selectedType), stdin);
    trimNewline(selectedType);

    for (int i = 0; i < roomCount; i++)
    {
        if (strcmp(hotelRooms[i].type, selectedType) == 0 && !hotelRooms[i].isOccupied)
        {
            foundRooms[foundCount++] = i;
        }
    }

    if (foundCount == 0)
    {
        printf("No rooms available for the selected type.\n");
        return;
    }

    // Step 2: Filter by View
    printf("\nAvailable Views: Sea View, City View\n");
    printf("Enter your preferred view: ");
    fgets(selectedView, sizeof(selectedView), stdin);
    trimNewline(selectedView);

    for (int i = 0; i < foundCount;)
    {
        if (strcmp(hotelRooms[foundRooms[i]].view, selectedView) != 0)
        {
            for (int j = i; j < foundCount - 1; j++)
            {
                foundRooms[j] = foundRooms[j + 1];
            }
            foundCount--;
        }
        else
        {
            i++;
        }
    }

    if (foundCount == 0)
    {
        printf("No rooms available for the selected view.\n");
        return;
    }

    // Step 3: Filter by AC Type
    printf("\nAvailable AC Types: AC Room, Non AC Room\n");
    printf("Enter your preferred AC type: ");
    fgets(selectedACType, sizeof(selectedACType), stdin);
    trimNewline(selectedACType);

    for (int i = 0; i < foundCount;)
    {
        if (strcmp(hotelRooms[foundRooms[i]].ac_type, selectedACType) != 0)
        {
            for (int j = i; j < foundCount - 1; j++)
            {
                foundRooms[j] = foundRooms[j + 1];
            }
            foundCount--;
        }
        else
        {
            i++;
        }
    }

    if (foundCount == 0)
    {
        printf("No rooms available for the selected AC type.\n");
        return;
    }

    // Step 4: Display Remaining Options
    printf("\nMatching Rooms:\n");
    printf("------------------------------------------------------------\n");
    printf("| Room No | Floor | Type     | View       | AC Type     | Price  |\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < foundCount; i++)
    {
        int idx = foundRooms[i];
        printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-6d |\n",
               hotelRooms[idx].roomNumber,
               hotelRooms[idx].floor,
               hotelRooms[idx].type,
               hotelRooms[idx].view,
               hotelRooms[idx].ac_type,
               hotelRooms[idx].basePrice);
    }

    printf("------------------------------------------------------------\n");

    // Step 5: Book Room
    printf("\nEnter the room number you want to book: ");
    scanf("%d", &selectedRoomNumber);

    for (int i = 0; i < foundCount; i++)
    {
        if (hotelRooms[foundRooms[i]].roomNumber == selectedRoomNumber)
        {
            hotelRooms[foundRooms[i]].isOccupied = 1;
            printf("Room %d has been successfully booked!\n", selectedRoomNumber);
            saveRoomsToFile(); // Save changes
            return;
        }
    }

    printf("Invalid room number. Booking failed.\n");
}

void saveRoomsToFile()
{
    FILE *file = fopen("rooms.txt", "w");
    if (file == NULL)
    {
        printf("Error: Unable to save room data to file.\n");
        return;
    }
    fwrite(&roomCount, sizeof(int), 1, file);
    fwrite(hotelRooms, sizeof(Room), roomCount, file);
    fclose(file);
    printf("Room data saved successfully.\n");
}

void loadRoomsFromFile()
{
    FILE *file = fopen("rooms.txt", "r");
    if (file == NULL)
    {
        printf("No saved room data found. Initializing default rooms.\n");
        return;
    }
    fread(&roomCount, sizeof(int), 1, file);
    fread(hotelRooms, sizeof(Room), roomCount, file);
    fclose(file);
    printf("Room data loaded successfully.\n");
}
