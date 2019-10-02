#include <RadiationChangeHandler.h>
#include <Arduino.h>
#include <BluetoothHandler.h>
#include <main.h>
#include <RadiationCalc.h>

float radVal;

void setupRadChange(int val) {
    radVal = val;
}

void pollRadValue(){
  radVal = (analogRead(A5) / 10);
  if(radVal > 100)
    radVal = 100;
  Serial.println(radVal);
  updateRadValue(radVal);
  btSendRadData(PROT_RAD_STATUS, (float)radVal);
}

float getRadValue() {
    return radVal;
}