/*
    Function for setting default values and open up the serial comms.
*/
void setupRFID();

/*
    Default RFID loop, constantly looking for a RFID tag and exits if none is present.
    If a tag is present, it is handled with and invertval of 2 seconds.
*/
void rc522ScannerLoop();

/*
    Function for grabbing the ID of the present RFID Tag
    Calls upon storeHexRepresentation() for storing as a char array.
*/
void getUniqueID();

/*
    Function for handling the authorization of the RFID tag.
    Checks if the tag is a registered tag, and clockes in/out aswell as sends
    the data to the bluetooth.
*/
void authorizeUser();

/*
    Function for keeping the timed interval of 2 seconds.
*/
void accessTimeReached();

/*
    Stores the RFID Tag as a char array using itoa.
*/
void storeHexRepresentation(char *b, const byte v);


void turnOffLed();

