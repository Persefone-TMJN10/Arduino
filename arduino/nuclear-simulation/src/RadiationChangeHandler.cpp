#include <RadiationChangeHandler.h>
#include <Arduino.h>
#include <BluetoothHandler.h>
#include <main.h>
#include <RadiationCalc.h>

float radVal = 1000;

void setupRadChange(int val) {
    radVal = val;
}

void pollRadValue(){
  int temp = analogRead(A5) / 10;
  if (radVal == temp)
    return;
  if (radVal  == (temp + 1) || radVal == (temp - 1) ||
      radVal == (temp + 2)  || radVal == (temp - 2))
    return;
  radVal = temp;
  if(radVal > 100)
    radVal = 100;
  Serial.println(radVal);
  updateRadValue(radVal);
  btSendRadData(PROT_RAD_STATUS, (float)radVal);
}

float getRadValue() {
    return radVal;
}