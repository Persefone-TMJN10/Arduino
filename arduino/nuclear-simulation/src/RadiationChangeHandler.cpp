#include <RadiationChangeHandler.h>
#include <Arduino.h>

int radVal;

void setupRadChange(int val) {
    radVal = val;
}

void pollRadValue(){
  radVal = analogRead(A5);
  Serial.println(radVal/10);
}

float getRadValue() {
    return (float) radVal;
}