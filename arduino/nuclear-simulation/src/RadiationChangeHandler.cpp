#include <RadiationChangeHandler.h>
#include <Arduino.h>
#include <BluetoothHandler.h>
#include <main.h>

int radVal;

void setupRadChange(int val) {
    radVal = val;
}

void pollRadValue(){
  radVal = analogRead(A5);
  Serial.println(radVal/10);
  btSendRadData(PROT_RAD_STATUS, (float)radVal);
}

float getRadValue() {
    return (float)radVal;
}