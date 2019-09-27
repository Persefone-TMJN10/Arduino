#include <LiquidCrystal.h>
#include <main.h>
#include <LcdHandler.h>

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

char* clockedStatus;

void setupLCD(){
   // lcd.setCursor(0, 0);
    lcd.begin(16,2);
    lcd.print("Hello World");
}

void updateLCD() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(clockedStatus);
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