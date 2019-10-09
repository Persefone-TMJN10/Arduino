/*
    Function for initializing with a different value than the default
*/
void setupRadChange(int);

/*
    Function called when the radiation value have been changed with the potentiometer
    Calls updateRadValue(); and btSendRadData();
*/
void pollRadChange();


float getRadValue();