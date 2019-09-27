#include <RadiationCalc.h>
#include <Arduino.h>
#include <WarningHandler.h>
#include <main.h>

#define RAD_TOLERANCE 500000

float reactorRadPerSec;
float roomCoef;
float protectiveCoef;
double radValue;
float humanRadPerSec;

void setupRadCalc(int reactRad, float roomConst, int protConst) {
    reactorRadPerSec = (float )reactRad;
    roomCoef = roomConst;
    protectiveCoef = (float)protConst;
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
}

float getRadCalcData(){
    return (reactorRadPerSec*roomCoef)/protectiveCoef;
}

void updateRadCalcData(int reactRad, float roomConst, int protConst){
    reactorRadPerSec = 30; //change when we have potentiometer
    roomCoef = 0.5; //change when we have room simulation
    protectiveCoef = 1; //change when we have hazmat simulation
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
    return ;
}

void updateRadTimer() {
    radValue += humanRadPerSec;
    Serial.print(radValue);
    Serial.println(" ");
     if(radValue >= RAD_TOLERANCE) {
         startBuzzer();
         digitalWrite(LED_R, HIGH);
     }
}