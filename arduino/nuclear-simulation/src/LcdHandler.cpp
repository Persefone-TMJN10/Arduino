#include <LiquidCrystal.h>
#include <main.h>
#include <LcdHandler.h>
#include <RadiationChangeHandler.h>

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

char* clockedStatus;
byte hours;
byte minutes;
byte seconds;
int clockedBool;

void setupLCD(){
   // lcd.setCursor(0, 0);
    lcd.begin(16,2);
    lcd.print("\\Nuclear Sim\\");
    lcd.setCursor(0,1);
    lcd.print("-:Persefone:-");
}

void updateLCD() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(clockedStatus);
    if (clockedBool) {
        lcd.setCursor(0,1);
        if (hours > 100) {
            lcd.print("time>100h");
        } else {
            lcd.print(hours);
            lcd.print(":");
            lcd.print(minutes);
            lcd.print(":");
            lcd.print(seconds);
        }
    } else {
        lcd.setCursor(0,1);
        lcd.print("-");
        lcd.print(":");
        lcd.print("-");
        lcd.print(":");
        lcd.print("--");
    }
    lcd.setCursor(9,1);
    lcd.print("RAD:");
    lcd.print((int)getRadValue());
}

void printTestLCD(){
    lcd.print("Hello World");
}

void printClockedStatus(int status) {
    lcd.setCursor(0,0);
    clockedBool = status;
    if (status) {
        clockedStatus = "Clocked In";
    } else {
        clockedStatus = "Clocked out";
    }
    updateLCD();
}

void printTimeLeft(byte h, byte m, byte s) {
    hours = h;
    minutes = m;
    seconds = s;
}

void printWarning() {
    lcd.setCursor(9,1);
    lcd.print("WARNING");
}