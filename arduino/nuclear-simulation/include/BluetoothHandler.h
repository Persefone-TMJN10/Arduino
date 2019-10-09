
/*
    Function for initializing bluetooth settings (open serial etc.)
*/
void setupBluetooth();


/*  Function for sending initial data for enviroment setup on remote
    Protocol == 0, uniqueID == RFID tag. radValue- hazmatStatus- roomId == variables
*/
void btSendInitialSetup(int protocol, char* uniqueID, float radValue, int hazmatStatus, int roomId);


/*  Function for sending a clocked out
    Protocol == 1, uniqueID == RFID tag
*/
void btSendClockedOut(int protocol, char* uniqueId);


/*  Function for sending radiator radiation value.
    Protocol == 2, radValue == (0 to 100)
*/
void btSendRadData(int protocol, float radValue);


/*  Function for sending hazmatStatus (on or off)
    Protocol == 3, hazmatStatus == ( 0 or 1)
*/
void btSendHazmatStatus(int protocol, int hazmatStatus);


/*  Function for sending a changing of room.
    Protocol == 4, roomId == (0 to 3)
*/
void btSendRoomStatus(int protocol, int roomId);
