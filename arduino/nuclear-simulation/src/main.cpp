#include <RC522_Handler.h>
#include <main.h>

void setup() {
  // put your setup code here, to run once:
  setupRFID();
}

void loop() {
  // put your main code here, to run repeatedly:
  rc522ScannerLoop();
}



