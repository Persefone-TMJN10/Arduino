#include <Arduino.h>
#include <time.h>
#include <main.h>
#include <SPI.h>
#include <BluetoothHandler.h>
#include <LcdHandler.h>

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

void debounceButton() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(HAZMAT_PIN);

  if (reading != lastHazmatButtonState) {  // If the switch changed, due to noise or pressing, reset the debouncing timer
    lastHazmatDebounceTime = millis();
    Serial.print("Hazmat state switch\n");
  }

  if ((millis() - lastHazmatDebounceTime) > debounceDelay) { //check if last last debounce is longer than delay
    if (reading != hazmatButtonState) {   // if the button state has changed:
      hazmatButtonState = reading;
      // only do TODO when button state is HIGH
      if (hazmatButtonState == HIGH) {
            Serial.print("Hazmat Button pressed\n");
            if(hazmatState == false){
              //  btSendHazmatStatus(PROT_HAZMAT_STATUS, 1);
                updateLcdHazmatStatus(1);
                Serial.print("Hazmat on\n");
                hazmatState = true;
            }
            else{
              //  btSendHazmatStatus(PROT_HAZMAT_STATUS, 0);
                updateLcdRoomStatus(0);
                Serial.print("Hazmat off\n");
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
    Serial.print("Room State switch\n");
  }
  if ((millis() - lastRoomDebounceTime) > debounceDelay) { //check if last last debounce is longer than delay
    if (reading != roomButtonState) {   // if the button state has changed:
      roomButtonState = reading;
      // only do TODO when button state is HIGH
      if (roomButtonState == HIGH) {
            Serial.print("Room Button pressed\n");
            switch (roomState)
            {
            case 0:
                updateLcdRoomStatus(0);
                Serial.print("Change to control room\n");
                roomState = 1;
                break;
            case 1:
                updateLcdRoomStatus(1);
                Serial.print("Change to reactor room\n");
                roomState = 2;
                break;
            case 2:      
                updateLcdRoomStatus(2);
                Serial.print("Change to break room\n");
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