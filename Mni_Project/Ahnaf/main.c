
/* Hotel-Management-System-Project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
// #define MAX_FLOORS 10
#define max_user 100
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"
#define USER_USERNAME "user"
#define USER_PASSWORD "user123"

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

typedef struct
{
    char name[30];
    char nid[30];
    long int number;
} customer;

// Global variables
Room hotelRooms[MAX_ROOMS];
customer c[max_user];
int roomCount = 0, MAX_FLOORS = 0;

// Function prototypes
void showMenu();
void initializeRooms();
void displayRooms();
void AddRoom();
void book_room();
void checkout();
void savefile();

int main()
{
    int choice = 0;
    printf("Enter the floor: ");

    scanf("%d", &MAX_FLOORS);
    initializeRooms(MAX_FLOORS);
    // savefile();

    while (choice != 5)
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
            AddRoom();
            break;
        case 3:
            book_room();
            break;
        case 4:
            checkout();
            break;
        case 5:
            printf("See you. Bye:)");
            savefile();
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// admin and user login interfage
int login(const char *username, const char *password)
{
    char inputUsername[20], inputPassword[20];

    printf("Enter Username: ");
    scanf("%s", inputUsername);
    printf("Enter Password: ");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void showAdminMenu()
{
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Room Booking\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void showUserMenu()
{
    printf("\n--- User Menu ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
} // code by al amin (login function )

void showMenu()
{
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Room Booking\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// rand();

void initializeRooms(int MAX_FLOORS)
{
    int roomNumber = 1;
    char *type[] = {"single", "double"};
    char *view[] = {"Sea View", "City View"};
    char *ac_type[] = {"AC Room", "Non AC Room"};
    int basePrice[] = {1350, 2000, 1200};
    int basePrice1[] = {3000, 5000};
    for (int floor = 1; floor <= MAX_FLOORS; floor++) // total floor in building
    {
        for (int i = 0; i < 4; i++) // akta floor e 4 ta room
        {
            hotelRooms[roomCount].roomNumber = (floor * 100) + (i + 1); // one kore room number bariteche // new fix room number by floor

            hotelRooms[roomCount].floor = floor; // for each iteration floor remain same
            // (rand() % 2 == 0)                      // amni akt logic to get value for other parameter
            strcpy(hotelRooms[roomCount].type, type[rand() % 2]);
            strcpy(hotelRooms[roomCount].view, view[rand() % 2]);
            strcpy(hotelRooms[roomCount].ac_type, ac_type[rand() % 2]);
            if (!strcmp(hotelRooms[roomCount].view, "Sea View") && !strcmp(hotelRooms[roomCount].ac_type, "AC Room"))
            {

                hotelRooms[roomCount].basePrice = basePrice1[rand() % 2];
            }
            else
            {
                hotelRooms[roomCount].basePrice = basePrice[rand() % 3];
            }
            hotelRooms[roomCount].isOccupied = 0;
            roomCount++;
        }
    }
    printf("Default rooms initialized!\n");
}

// done by tahsin
void AddRoom()
{
    int roomNumber, floor, basePrice, isOccupied;
    char type[20], view[20];

    if (roomCount < MAX_ROOMS) // Ensure roomCount is less than MAX_ROOMS
    {
        // Prompt user for room details
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);
        printf("Enter Floor: ");
        scanf("%d", &floor);
        getchar();
        printf("Enter Room Type (e.g., Single, Double): ");
        scanf("%[^\n]s", type);
        getchar();
        printf("Enter View (e.g., Sea, City): ");
        scanf("%[^\n]s", view);
        getchar();
        printf("Enter Base Price: ");
        scanf("%d", &basePrice);
        printf("Is the room occupied? (1 for Yes, 0 for No): ");
        scanf("%d", &isOccupied);

        // Populate hotelRooms array
        hotelRooms[roomCount].roomNumber = roomNumber;
        hotelRooms[roomCount].floor = floor;
        hotelRooms[roomCount].basePrice = basePrice;
        hotelRooms[roomCount].isOccupied = isOccupied;
        strcpy(hotelRooms[roomCount].type, type);
        strcpy(hotelRooms[roomCount].view, view);

        roomCount++;
        printf("\n\n  ------ Room added successfully.------  \n");
        printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nBase Price: %d\nOccupied: %d\n",
               roomNumber, floor, type, view, basePrice, isOccupied);
    }
    else
    {
        printf("Cannot add more rooms. Maximum capacity reached.\n");
    }
}

void displayRooms()
{
    /*printf("\n--- Available Rooms ---\n");
    for (int i = 0; i < roomCount; i++)
    {
        if (!hotelRooms[i].isOccupied)
        {
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, AC type: %s, Base Price: %dtake\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view, hotelRooms[i].ac_type,
                   hotelRooms[i].basePrice);
        }
    }
    printf("\n--- Occupied Rooms ---\n");
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].isOccupied)
        {
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, AC type: %s, Base Price: %dtake\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view, hotelRooms[i].ac_type,
                   hotelRooms[i].basePrice);
        }
    }*/
    printf("\nRoom Data:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
    printf("-----------------------------------------------------------------------------\n");

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

    printf("----------------------------------------------------------------------------------\n");
}

void book_room()
{
    int roomNumber = 0;
    char type[30], view[30], ac[30];
    int foundroom[MAX_ROOMS];
    int foundcount = 0;
    int found = 0;

    printf("Enter the room type (single/double): ");
    scanf("%[^\n]s", type);
    getchar(); // to clear the buffer

    // Filter by type and store it in custom local array
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].isOccupied == 0 && strcmp(hotelRooms[i].type, type) == 0)
        {
            foundroom[foundcount++] = i;
        }
    }

    printf("Do you want ac or non ac room? -> ");
    scanf("%[^\n]s", ac);
    getchar();

    // Filter by ac
    for (int i = 0; i < foundcount;)
    {
        if (strcmp(hotelRooms[foundroom[i]].ac_type, ac) != 0)
        {
            for (int j = i; j < foundcount - 1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // removing the not match item
            }
            foundcount--;
        }
        else
        {
            i++;
        }
    }

    printf("Do you prefer Sea View or City View? ");
    scanf("%[^\n]s", view);
    getchar();

    // Filter by view
    for (int i = 0; i < foundcount;)
    {
        if (strcmp(hotelRooms[foundroom[i]].view, view) != 0)
        {
            for (int j = i; j < foundcount - 1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // removing the not match item
            }
            foundcount--;
        }
        else
        {
            i++;
        }
    }

    if (foundcount == 0)
    {
        printf("No available rooms match your criteria.\n");
    }
    else
    {
        printf("\nRoom Data:\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
        printf("-----------------------------------------------------------------------------\n");

        for (int i = 0; i < foundcount; i++)
        {
            printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-8s | %-6d |\n",
                   hotelRooms[foundroom[i]].roomNumber,
                   hotelRooms[foundroom[i]].floor,
                   hotelRooms[foundroom[i]].type,
                   hotelRooms[foundroom[i]].view,
                   hotelRooms[foundroom[i]].ac_type,
                   hotelRooms[foundroom[i]].isOccupied ? "Yes" : "No",
                   hotelRooms[foundroom[i]].basePrice);
        }

        printf("----------------------------------------------------------------------------------\n");
    }
}


void checkout()
{
    int roomNumber = 0;
    printf("Enter Room number: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++)
    {
        if (roomNumber == hotelRooms[i].roomNumber)
        {
            if (hotelRooms[i].isOccupied)
            {
                hotelRooms[i].isOccupied = 0;
                printf("You have been succesfully checkout from Room %d!\n", hotelRooms[i].roomNumber);
            }
            else
            {
                printf("Room %d is already Unoccupied. So checkout is not possible.\n", hotelRooms[i].roomNumber);
            }
            break;
        }
    }
    // done by sahaf
}

void savefile()
{
    FILE *f1;
    f1 = fopen("text2.txt", "w");
    // for (int i = 0; i < roomCount; i++)
    // {
    // fwrite(hotelRooms, sizeof(Room), 1, f1);
    //}
    fwrite(&roomCount, sizeof(int), 1, f1);
    fwrite(hotelRooms, sizeof(Room), roomCount, f1);
    fclose(f1);
}

// void book_room(char hotel[ROOMS][20], int room) {
//     if (strcmp(hotel[room], "Available") == 0) {
//         strcpy(hotel[room], "Booked");
//         printf("Room %d has been booked successfully!\n", room + 1);
//     } else {
//         printf("Room %d is already booked.\n", room + 1);
//     }
// }

// int calculatePrice(Room *room, int stayDuration, int month) {
//     int price = room->basePrice;

//     if (isPeakSeason(month)) {
//         price *= 1.2;
//     }

//     if (stayDuration > 7) {
//         price *= 0.85;
//     } else if (stayDuration < 3) {
//         price *= 1.15;
//     }

//     if (strcmp(room->view, "Sea View") == 0) {
//         price *= 1.2;
//     }

//     return price * stayDuration;
// }

// By sAhAf🙂

// By TeaM ScorPIoN🙂
