#include <BluetoothHandler.h>

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

void btSendData() {
String temp = "String";
  //IMPORTANT: The complete String has to be of the Form: 1234,1234,1234,1234;

//(every Value has to be seperated through a comma (',') and the message has to

//end with a semikolon (';'))

hc06.print(val1);
val1 = val1 + 1;
hc06.print(",");

hc06.print(val2);
val2 = val2 + 2;
hc06.print(",");

hc06.print(val3);
val3 = val3 + 10;
hc06.print(",");

hc06.print(val4);
val4 = val4 + 100;
hc06.print(",");

hc06.print(temp);

hc06.print(";");

//message to the receiving device

delay(20);
}

