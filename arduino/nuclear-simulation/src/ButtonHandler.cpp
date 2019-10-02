#include <Arduino.h>
#include <time.h>
#include <main.h>
#include <SPI.h>

int buttonState;             // the current reading from the input pin
int lastHazmatButtonState = LOW;   // the previous reading from the input pin
bool hazmatState = false;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setupButtons() {
  pinMode(HAZMAT_PIN, INPUT);
  Serial.begin(9600);
}

void debounceButton() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(HAZMAT_PIN);

  if (reading != lastHazmatButtonState) {  // If the switch changed, due to noise or pressing, reset the debouncing timer
    lastDebounceTime = millis();
    Serial.print("State switch\n");
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { //check if last last debounce is longer than delay
    if (reading != buttonState) {   // if the button state has changed:
      buttonState = reading;
      // only do TODO when button state is HIGH
      if (buttonState == HIGH) {
            Serial.print("Button pressed\n");
            if(hazmatState == false){
                Serial.print("Hazmat on\n");
                hazmatState = true;
            }
            else{
                Serial.print("Hazmat off\n");
                hazmatState = false;
            }
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastHazmatButtonState = reading;
}

