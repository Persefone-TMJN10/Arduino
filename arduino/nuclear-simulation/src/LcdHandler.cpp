#include <LiquidCrystal.h>
#include <main.h>
#include <LcdHandler.h>

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

char* clockedStatus;
byte hours;
byte minutes;
byte seconds;

void setupLCD(){
   // lcd.setCursor(0, 0);
    lcd.begin(16,2);
    lcd.print("Hello World");
}

void updateLCD() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(clockedStatus);
    if (clockedStatus) {
        lcd.setCursor(0,1);
        lcd.print(hours);
        lcd.print(":");
        lcd.print(minutes);
        lcd.print(":");
        lcd.print(seconds);
    }
}

void printTestLCD(){
    lcd.print("Hello World");
}

void printClockedStatus(int status) {
    lcd.setCursor(0,0);
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