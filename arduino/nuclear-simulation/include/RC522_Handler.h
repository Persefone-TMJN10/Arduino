#include <BluetoothHandler.h>
#include <main.h>

#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000

void rc522ScannerLoop();
void printDEC(byte *, byte); // Grab and print RFID UID
void setupRFID();
String getUniqueID();
boolean authorizeUID();
