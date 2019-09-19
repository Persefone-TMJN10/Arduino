#include <BluetoothHandler.h>

byte BTVal;

void setupBluetooth() {
    pinMode(RX_PIN, INPUT);
    pinMode(TX_PIN, OUTPUT);
    digitalWrite(RX_PIN, HIGH);

}