#include <BluetoothHandler.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <main.h> 

byte BTVal;
SoftwareSerial hc06(TX_PIN,RX_PIN);

int sensorValue = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

void setupBluetooth() {
  hc06.begin(9600);

}

void btLoop() {

}

void btSendData(int protocol, char* uniqueID, int clockedStatus) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(uniqueID);
  hc06.print(",");
  hc06.print(clockedStatus);
  hc06.print(";");
  delay(20);

}

void btSendRadData(int protocol, char* uniqueID, unsigned long int radValue) {
  hc06.print(protocol);
  hc06.print(",");
  hc06.print(uniqueID);
  hc06.print(",");
  hc06.print(radValue);
  hc06.print(";");
  delay(20);
}

