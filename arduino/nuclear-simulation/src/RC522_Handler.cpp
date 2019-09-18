#include <RC522_Handler.h>



MFRC522 mfrc522(SS_PIN, RST_PIN); // FRID RC522 instance

void setupRFID() {
  // RC522 setup
  Serial.begin(9600); // init serial communications with the PC
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan PICC to see UID and type...");
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

  // Check if ID is registered and clocked in
  if (authorizeUID()){
    // Send BlueTooth (?)
    // turn on green led
    digitalWrite(LED_G, HIGH);
    delay(ACCESS_DELAY);
    digitalWrite(LED_G, LOW);
  } else {
    //turn on red led
    delay(DENIED_DELAY);
  }

	// Dump debug info about the card. PICC_HaltA() is automatically called.
	// mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

boolean authorizeUID () {
  // Hard coded ID should be replaced with the user list
  if (getUniqueID().substring(1) == "80 53 80 4D") {
    return true;
  }
  return false;
}

// RFID Unique ID printer
void printDEC(byte *buffer, byte bufferSize) {
  for(byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i]);
  }
  // Change line once the entire UID is printed
  Serial.println(" ");
}

// RFID Unique ID HEX graber
String getUniqueID (){
  String uniqueID= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     uniqueID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     uniqueID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
    uniqueID.toUpperCase();
    return uniqueID;
}