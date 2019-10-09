/*
    Function for setting default values for the radiation calculation environment
*/
void setupRadCalc(float,float,float);

/*
    Function used for updating the local environment variables.
    (radiation value, room radiation coefficient, protective gear radiation coefficient)
*/
void updateRadCalcData(int,float,int);

/*
    Function used for updating the radiation time limit estimation.
*/
void updateRadTimer();


/*
    Function used for reseting the total value upon clocked outs
*/
void resetRadValue();


/*
    Function used for updating radiation value (0 to 100) upon simulation with potentiometer
*/
void updateRadValue(int radVal);


/*
    Function used for updating room status (0 to 2) upon simulation with buttons.
*/
void updateRoomStatus(int roomVal);


/*
    Function used for updating hazmat status (0 to 1) upon simulation with buttons.
*/
void updateHazmatStatus(int hazmatVal);

int getRoomStatus();

int getHazmatStatus();

double getRadToleranceLeft();

float getRadCalcData();

