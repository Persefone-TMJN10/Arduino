#include <Arduino.h> // required for boolean

#define MAX_NR_OF_USERS 5

// Typedef for storing personel data with the possibility for multiple technicans
typedef struct personel {
  char uniqueid[9];
  bool clockStatus;
  float radValue;
} personel;

/*
  Function for cheking if the RFID tag is connected to a registered technician.
*/
boolean checkIfRegistered(char*);

/*
  Function for checking if the technicans is performing a clock in or a clock out.
*/
boolean isClockedIn(char*);

/*
  Initializes the user list.
*/
void setupUsers();



