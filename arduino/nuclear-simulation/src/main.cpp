#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <TimedAction.h>
#include <Wire.h>

#include <RfidHandler.h>
#include <BluetoothHandler.h>
#include <UserHandler.h>
#include <RadiationCalc.h>
#include <main.h>
#include <LcdHandler.h>

TimedAction countDown = TimedAction(1000, updateRadTimer);



void setup() {
  // put your setup code here, to run once:
  countDown.disable();
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(E_PIN, OUTPUT);
  pinMode(D4_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  pinMode(D6_PIN, OUTPUT);
  pinMode(D7_PIN, OUTPUT);
  //pinMode(LED_R, OUTPUT);
  pinMode(3, OUTPUT);
  setupRFID();
  setupRadCalc(400000, BREAK_ROOM, HAZMAT);
  setupBluetooth();
  setupLCD();
}

void loop() {
  // put your main code here, to run repeatedly:
  rc522ScannerLoop();
  countDown.check();
  // btLoop();
}

void enableCountDown() {
  countDown.enable();
}

void resetCountDown() {
  resetRadValue();
  countDown.disable();
}



