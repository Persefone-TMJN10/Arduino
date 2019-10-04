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
#include <ButtonHandler.h>
#include <RadiationChangeHandler.h>


TimedAction countDown = TimedAction(1000, updateRadTimer);
TimedAction radPoll = TimedAction(1900, pollRadValue);
TimedAction lcdRefresh = TimedAction(500, updateLCD);


void setup() {
  // put your setup code here, to run once:
  countDown.disable();
  lcdRefresh.disable();
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(E_PIN, OUTPUT);
  pinMode(D4_PIN, OUTPUT);
  pinMode(D5_PIN, OUTPUT);
  pinMode(D6_PIN, OUTPUT);
  pinMode(D7_PIN, OUTPUT);
  // Potentiometer pin
  //pinMode(LED_R, OUTPUT);
  pinMode(3, OUTPUT);
  setupRFID();
  setupRadCalc(30, BREAK_ROOM, CLOTHES);
  setupRadChange(30);
  setupBluetooth();
  setupLCD();
  setupButtons();
}

void loop() {
  // put your main code here, to run repeatedly:
  rc522ScannerLoop();
  countDown.check();
  radPoll.check();
  lcdRefresh.check();
  hazmatButton();
  roomButton();
}

void enableCountDown() {
  lcdRefresh.enable();
  countDown.enable();
}

void resetCountDown() {
  resetRadValue();
  countDown.disable();
}



