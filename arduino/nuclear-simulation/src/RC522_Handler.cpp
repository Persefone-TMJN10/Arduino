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

	// Dump debug info about the card. PICC_HaltA() is automatically called.
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

// RFID Unique ID printer
void printDEC(byte *buffer, byte bufferSize) {
  for(byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i]);
  }
  // Change line once the entire UID is printed
  Serial.println(" ");
}