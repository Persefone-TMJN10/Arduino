#include <RadiationCalc.h>
#include <Arduino.h>
#include <WarningHandler.h>
#include <main.h>
#include <LcdHandler.h>

#define RAD_TOLERANCE 500000
#define ms_per_hour  3600000
#define ms_per_min    60000
#define ms_per_sec    1000

float reactorRadPerSec;
float roomCoef;
float protectiveCoef;
double radValue;
float humanRadPerSec;

int roomStatus;
int hazmatStatus;


void setupRadCalc(float reactRad, float roomConst, float protConst) {
    reactorRadPerSec = reactRad;
    roomCoef = roomConst;
    protectiveCoef = protConst;
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
    roomStatus = 0;
    hazmatStatus = 0;
    Serial.print(humanRadPerSec);
    Serial.print(":");
    Serial.print(reactorRadPerSec);
    Serial.print(":");
    Serial.print(roomCoef);
    Serial.print(":");
    Serial.print(protectiveCoef);
    Serial.println("");
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
    double radLeft = RAD_TOLERANCE - radValue;
    float mili = (radLeft/humanRadPerSec)*1000;
    byte hour = (mili / ms_per_hour);
    mili -= (hour * ms_per_hour);
    byte minute = (mili / ms_per_min);
    mili -= (minute * ms_per_min);
    byte second = (mili / ms_per_sec);
    if (second < 61) {
        printTimeLeft(hour,minute,second);
        updateLCD();
    }
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.print(second);
    Serial.println("");
     if(radValue >= RAD_TOLERANCE) {
         printWarning();
         startBuzzer();
     }
}

void resetRadValue() {
    radValue = 0;
}
