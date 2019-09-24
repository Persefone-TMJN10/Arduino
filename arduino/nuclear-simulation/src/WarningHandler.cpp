#include <WarningHandler.h>
#include <Arduino.h>
#include <main.h>

void startBuzzer(){

tone(BUZZER_PIN, 500, 1000);

}