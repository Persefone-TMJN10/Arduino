#include <MFRC522.h>
#include <Arduino.h>
#include <SPI.h>
#include <TimedAction.h>

#include <RfidHandler.h>
#include <BluetoothHandler.h>
#include <UserHandler.h>
#include <main.h>
#include <WarningHandler.h>
#include <RadiationCalc.h>



MFRC522 mfrc522(SS_PIN, RST_PIN); // FRID RC522 instance
TimedAction accessDelay = TimedAction(2000, accessTimeReached);


char uid[9]; // 4 x 2 chars for the 4 bytes + trailing '\0'

void setupRFID() {
  // RC522 setup
  Serial.begin(9600); // init serial communications with the PC
  SPI.begin();
  mfrc522.PCD_Init();
  setupUsers();
  // Serial.println("Scan PICC to see UID and type...");
}

void rc522ScannerLoop() {
  	// Look for new cards
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  accessDelay.check();

}

// RFID Unique ID HEX graber
void getUniqueID () {
    for (byte i = 0; i < mfrc522.uid.size; ++i) { // read id (in parts)
        storeHexRepresentation(&uid[2 * i], mfrc522.uid.uidByte[i]);
      }
}

void accessTimeReached() {
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  getUniqueID();
  authorizeUser();
}

void authorizeUser() {
  if (checkIfRegistered(uid)){
    if(isClockedIn(uid)){
      btSendData(CLOCKED_STATUS, uid, CLOCKED_IN);
      btSendRadData(RADIATION_VALUE, uid, getRadCalcData());
      digitalWrite(LED_G, HIGH);
      
    } else {
      btSendData(CLOCKED_STATUS, uid, CLOCKED_OUT);
      digitalWrite(LED_B, HIGH);
    }
  }
}

// store on 2 char the Hex represnetation of byte v
// adds a trailing '\0'
// so b should point to an array with at least 3 bytes available to contain the representation
void storeHexRepresentation(char *b, const byte v) {
  if (v <= 0xF) {
    *b = '0';
    b++;
  }
  itoa(v, b, 16);
}
