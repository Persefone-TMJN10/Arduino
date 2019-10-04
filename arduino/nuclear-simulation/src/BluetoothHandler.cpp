#include <BluetoothHandler.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <RadiationCalc.h>
#include <main.h> 

byte BTVal;
SoftwareSerial hc06(TX_PIN,RX_PIN);

void setupBluetooth() {
  hc06.begin(9600);

}

void btLoop() {

}

void btSendInitialSetup(int protocol, char* uniqueID, float radValue, int hazmatStatus, int roomId) {
  Serial.println(protocol);
    Serial.println(uniqueID);
      Serial.println(radValue);
        Serial.println(hazmatStatus);
          Serial.println(roomId);
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(uniqueID);
  hc06.print(",");
  hc06.print(radValue);
  hc06.print(",");
  hc06.print(hazmatStatus);
  hc06.print(",");
  hc06.print(roomId);
  hc06.print(";");
  delay(20);

}

void btSendClockedOut(int protocol, char* uniqueId) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(uniqueId);
  hc06.print(";");
  delay(20);
}

void btSendRadData(int protocol, float radValue) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(radValue);
  hc06.print(",");
  hc06.print(getRadToleranceLeft());
  hc06.print(";");
  delay(20);
}

void btSendHazmatStatus(int protocol, int hazmatStatus) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(hazmatStatus);
  hc06.print(",");
  hc06.print(getRadToleranceLeft());
  hc06.print(";");
  delay(20);
}

void btSendRoomStatus(int protocol, int roomId) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(roomId);
  hc06.print(",");
  hc06.print(getRadToleranceLeft());
  hc06.print(";");
  delay(20);
}

