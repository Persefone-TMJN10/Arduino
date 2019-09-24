#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <TimedAction.h>

#include <RfidHandler.h>
#include <BluetoothHandler.h>
#include <UserHandler.h>
#include <RadiationCalc.h>
#include <main.h>

TimedAction countDown = TimedAction(1000, updateRadTimer);



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(3, OUTPUT);
  setupRadCalc(30, CONTROL_ROOM, HAZMAT);
  setupRFID();
  setupBluetooth();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  rc522ScannerLoop();
  countDown.check();
  // btLoop();
}



