#include <RC522_Handler.h>



MFRC522 mfrc522(SS_PIN, RST_PIN); // FRID RC522 instance

void setupRFID() {
  // RC522 setup
  Serial.begin(9600); // init serial communications with the PC
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan PICC to se UID and type...");
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
    // if (ClockinggIn) 
    // Send BlueTooth (?)
    if(isClockedIn(getUniqueID().substring(1))){
      digitalWrite(LED_G, HIGH);
      delay(ACCESS_DELAY);
      digitalWrite(LED_G, LOW);
    } else {
      digitalWrite(LED_B, HIGH);
      delay(ACCESS_DELAY);
      digitalWrite(LED_B, LOW);
    }
    // else clocking out
    // Send bluetooth
  } else {
    //turn on red led
    delay(DENIED_DELAY);
  }

	// Dump debug info about the card. PICC_HaltA() is automatically called.
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

boolean authorizeUID () {
  // Hard coded ID should be replaced with the user list
  if (checkUID(getUniqueID().substring(1))) {
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

