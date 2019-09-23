#include <RadiationCalc.h>


#define BREAK_ROOM 0.1
#define CONTROL_ROOM 0.5
#define REACTOR_ROOM 1.6
#define HAZMAT 5
#define CLOTHES 1


float getRadCalcData(int reactorRadPerSec, double roomCoef, int protectiveCoef){

    int humanRadPerSec;
    reactorRadPerSec = 30; //change when we have potentiometer
    roomCoef = 0.5; //change when we have room simulation
    protectiveCoef = 1; //change when we have hazmat simulation
    humanRadPerSec = (reactorRadPerSec*roomCoef)/protectiveCoef;

    return humanRadPerSec;
}