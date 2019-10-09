/*
    Setup initial values, default text and default cursor pos.
*/
void setupLCD();

/*
    Function for updating text. Sets cursor to correct pos depending on whats to be written.
    Is called from multiple sources.
*/
void updateLCD();

/*
    Function for printing Clocked in or out status.
    Calls updateLCD();
*/
void printClockedStatus(int);

/*
    Function sets time variables for correct time estimation print out.
    Called from RadiationCalc.cpp and in turn calls updateLCD();
    (byte hours,byte minutes,byte seconds);
*/
void printTimeLeft(byte,byte,byte);

/*
    Simple function for printing a warning on the LCD.
*/
void printWarning();

/*
   Function for updating the roomStatus
   Calls updateLCD();
*/
void updateLcdRoomStatus(int);

/*
    Function for updating hazmatStatus
    Calls updateLCD();
*/
void updateLcdHazmatStatus(int);