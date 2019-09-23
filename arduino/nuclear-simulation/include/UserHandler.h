#include <Arduino.h> // required for boolean

#define MAX_NR_OF_USERS 5

typedef struct personel {
  char uniqueid[9];
  bool clockStatus;
  float radValue;
} personel;

boolean checkIfRegistered(char*);
boolean isClockedIn(char*);
void setupUsers();



