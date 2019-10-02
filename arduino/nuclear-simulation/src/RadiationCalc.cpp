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
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
    return ;
}

void updateRadTimer() {
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
    radValue += humanRadPerSec;
    double radLeft = RAD_TOLERANCE - radValue;

    Serial.println(protectiveCoef);

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

void updateRadValue(int radVal) {
    reactorRadPerSec = radVal;
}

void updateRoomStatus(int roomVal) {
     Serial.println("ROOM CHANGE");
    roomStatus = roomVal;
    switch(roomVal) {
        case 0:
            roomCoef = BREAK_ROOM;
            break;
        case 1:
            roomCoef = CONTROL_ROOM;
            break;
        case 2:
            roomCoef = REACTOR_ROOM;
            break;
    }
    
    Serial.println(roomCoef);

}

void updateHazmatStatus(int hazmatVal) {
    Serial.println("HAZMAT CHANGE");
    hazmatStatus = hazmatVal;
    switch(hazmatVal) {
        case 0:
            protectiveCoef = CLOTHES;
            break;
        case 1:
            protectiveCoef = HAZMAT;
            break;
    }
    Serial.println("HAZMAT");
    Serial.println(hazmatVal);
    Serial.println(protectiveCoef);
}

int getRoomStatus(){
    return roomStatus;
}

int getHazmatStatus(){
    return hazmatStatus;
}
