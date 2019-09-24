#include <RadiationCalc.h>
#include <Arduino.h>


#define BREAK_ROOM 0.1
#define CONTROL_ROOM 0.5
#define REACTOR_ROOM 1.6
#define HAZMAT 5
#define CLOTHES 1
#define RAD_TOLERANCE 500000

int reactorRadPerSec;
double roomCoef;
int protectiveCoef;
int radValue;
int humanRadPerSec;

void setupRadCalc(int reactRad, double roomConst, int protConst) {
    humanRadPerSec = 0;
    reactorRadPerSec = reactRad;
    roomCoef = roomConst;
    protectiveCoef = protConst;
}

float getRadCalcData(){
    return (reactorRadPerSec*roomCoef)/protectiveCoef;
}

void updateRadCalcData(int reactRad, double roomConst, int protConst){
    reactorRadPerSec = 30; //change when we have potentiometer
    roomCoef = 0.5; //change when we have room simulation
    protectiveCoef = 1; //change when we have hazmat simulation
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;
    return ;
}

void updateRadTimer() {
    radValue += humanRadPerSec;
    // if(radValue >= RAD_TOLERANCE)
}