#include <LiquidCrystal.h>
#include <main.h>
#include <LcdHandler.h>

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setupLCD(){
   // lcd.setCursor(0, 0);
    lcd.begin(16,2);
    lcd.print("Hello World");
}

void printTestLCD(){
    lcd.print("Hello World");
}