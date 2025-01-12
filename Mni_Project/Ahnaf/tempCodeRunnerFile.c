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
            for (int j = i; j < foundcount-1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // removing the not match item
            }
            foundcount--;
        }
        else{
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
            for (int j = i; j < foundcount-1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // removing the not match item
            }
            foundcount--;
        }
        else{
            i++;
        }
    }

    for (int i = 0; i < foundcount; i++)
    {
        printf("\nRoom Data:\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
        printf("-----------------------------------------------------------------------------\n");

        for (int i = 0; i < roomCount; i++)
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

    // for (int i = 0; i < roomCount; i++)
    // {
    //     if (!hotelRooms[i].isOccupied && strcmp(hotelRooms[i].type, type) == 0)
    //     {
    //         printf("Do you want AC or Non-AC? ");
    //         scanf("%[^\n]s", ac);
    //         getchar(); // to clear the buffer

    //         if (strcmp(hotelRooms[i].ac_type, ac) == 0)
    //         {
    //             printf("Do you prefer Sea View or City View? ");
    //             scanf("%[^\n]s", view);
    //             getchar(); // to clear the buffer

    //             if (strcmp(hotelRooms[i].view, view) == 0)
    //             {
    //                 printf("Room available: %d on floor %d\n", hotelRooms[i].roomNumber, hotelRooms[i].floor);
    //                 printf("Enter Room number: ");
    //                 scanf("%d", &roomNumber);
    //                 getchar();

    //                 if (roomNumber == hotelRooms[i].roomNumber)
    //                 {
    //                     hotelRooms[i].isOccupied = 1;
    //                     found = 1;
    //                     printf("Room %d has been booked successfully!\n", hotelRooms[i].roomNumber);
    //                     break;
    //                 }
    //             }
    //         }
    //     }

    //     if (found)
    //         break;
    // }

    if (!found)
    {
        printf("No available rooms match your criteria.\n");
    }
}