#include <RC522_Handler.h>
#include <BluetoothHandler.h>
#include <main.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  setupRFID();
  setupBluetooth();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  rc522ScannerLoop();
}



