#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <main.h>

void rc522ScannerLoop();
void printDEC(byte *, byte); // Grab and print RFID UID
void setupRFID();
String getUniqueID();