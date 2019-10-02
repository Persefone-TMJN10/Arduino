
#define SS_PIN 10
#define RST_PIN 9

#define LED_G 5 // Define green LED to pin 5
#define LED_B 4 // Define blue LED to pin 4
#define LED_R 3 // Define red LED to pin 3

// Clocked in and out status
#define CLOCKED_IN 1
#define CLOCKED_OUT 0

// Bluetooth delays for serial com
#define bit9600Delay 84  
#define halfBit9600Delay 42
#define bit4800Delay 188 
#define halfBit4800Delay 94
// Bluetooth transmit and reciever pins
#define RX_PIN 6
#define TX_PIN 7

// Bluetooth protocol
#define PROT_CLOCKED_IN 0 // Data associated with clocked in or out
#define PROT_CLOCKED_OUT 1 // Data associated with the calculated radiation value
#define PROT_RAD_STATUS 2
#define PROT_HAZMAT_STATUS 3
#define PROT_ROOM_STATUS 4


// Radiation default data defines
#define BREAK_ROOM 0.1
#define CONTROL_ROOM 0.5
#define REACTOR_ROOM 1.6
#define HAZMAT 5
#define CLOTHES 1

//LCD Pin defines
#define RS_PIN 3
#define E_PIN 14 //A0
#define D0_PIN
#define D1_PIN
#define D2_PIN
#define D3_PIN
#define D4_PIN 15 //A1
#define D5_PIN 16 //A2
#define D6_PIN 17 //A3
#define D7_PIN 18 //A4

// Function Defenition
void enableCountDown();
void resetCountDown();
void pollRadValue();

//Button Pin Defines
#define HAZMAT_PIN 2
#define ROOM_PIN 8

