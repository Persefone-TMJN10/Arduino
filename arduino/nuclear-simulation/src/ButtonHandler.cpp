#include <Arduino.h>
#include <time.h>
#include <main.h>
#include <SPI.h>
#include <BluetoothHandler.h>
#include <LcdHandler.h>
#include <RadiationCalc.h>

//HAZMAT 
int hazmatButtonState;             // the current reading from the hazmat input pin
int lastHazmatButtonState = LOW;   // the previous reading from the hazmat input pin
bool hazmatState = false;  // the prevous hazmat state, false = hazmat off, true = hazmat on
unsigned long lastHazmatDebounceTime = 0;  // the last time the hazmat output pin was toggled

//ROOM
int roomButtonState;            // the current reading from the hazmat input pin
int lastRoomButtonState = LOW; // the previous reading from the room input pin
int roomState = 0; // 0 = break room, 1 = control room, 2 = reactor room
unsigned long lastRoomDebounceTime = 0;// the last time the room output pin was toggled


unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setupButtons() {
  pinMode(HAZMAT_PIN, INPUT);
  pinMode(ROOM_PIN, INPUT);
  Serial.begin(9600);
}

void hazmatButton() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(HAZMAT_PIN);

  if (reading != lastHazmatButtonState) {  // If the switch changed, due to noise or pressing, reset the debouncing timer
    lastHazmatDebounceTime = millis();
  }

  if ((millis() - lastHazmatDebounceTime) > debounceDelay) { //check if last last debounce is longer than delay
    if (reading != hazmatButtonState) {   // if the button state has changed:
      hazmatButtonState = reading;
      // only do when button state is HIGH
      if (hazmatButtonState == HIGH) {
            if(hazmatState == false){
                updateHazmatStatus(1);
                updateLcdHazmatStatus(1);
                btSendHazmatStatus(PROT_HAZMAT_STATUS, 1);
                hazmatState = true;
            }
            else{
                updateHazmatStatus(0);
                updateLcdHazmatStatus(0);
                btSendHazmatStatus(PROT_HAZMAT_STATUS, 0);
                hazmatState = false;
            }
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastHazmatButtonState = reading;
}

void roomButton(){
    // read the state of the switch into a local variable:
  int reading = digitalRead(ROOM_PIN);

  if (reading != lastRoomButtonState) {  // If the switch changed, due to noise or pressing, reset the debouncing timer
    lastRoomDebounceTime = millis();
  }
  if ((millis() - lastRoomDebounceTime) > debounceDelay) { //check if last last debounce is longer than delay
    if (reading != roomButtonState) {   // if the button state has changed:
      roomButtonState = reading;
      // only do when button state is HIGH
      if (roomButtonState == HIGH) {
            switch (roomState)
            {
            case 0:
                updateRoomStatus(1);
                updateLcdRoomStatus(1);
                btSendRoomStatus(PROT_ROOM_STATUS, 1);
                roomState = 1;
                break;
            case 1:
                updateRoomStatus(2);
                updateLcdRoomStatus(2);
                btSendRoomStatus(PROT_ROOM_STATUS, 2);
                roomState = 2;
                break;
            case 2:      
                updateRoomStatus(0);
                updateLcdRoomStatus(0);
                btSendRoomStatus(PROT_ROOM_STATUS, 0);
                roomState = 0;
                break;
            default:
                break;
            }
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastRoomButtonState:
  lastRoomButtonState = reading;
}