void initializeRooms() {
    int roomNumber = 101;
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