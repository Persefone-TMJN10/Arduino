#include <UserHandler.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Arduino.h>

 personel technician[MAX_NR_OF_USERS]; // Personel List with accosiated variables, can be of increased size

boolean checkIfRegistered(char* uid) {
  for (int i = 0; i < 10; i++) {
    if(strcmp(uid, technician[i].uniqueid) == 0) {
      technician[i].clockStatus = 1 - technician[i].clockStatus;
      return true;
    }
  }
  return false;
}

boolean isClockedIn(char* uid) {
    for (int i = 0; i < MAX_NR_OF_USERS; i++) {
    if(strcmp(uid, technician[i].uniqueid) == 0) {
      if(technician[i].clockStatus == 1) {
        return true;
      }
      else {
        return false;
      }
    }
  }
  // Function cannot be called if there is a mathing id in the user list
}

void setupUsers() {
  strcpy(technician[3].uniqueid, "8053804d");
 
  for (int i = 0; i < MAX_NR_OF_USERS; i++) {
    technician[i].clockStatus = 0;
    technician[i].radValue = 0;
  }
}


