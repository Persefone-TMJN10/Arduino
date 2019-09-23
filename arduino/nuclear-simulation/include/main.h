
#define SS_PIN 10
#define RST_PIN 9

#define LED_G 5 // Define green LED to pin 5
#define LED_B 4 // Define blue LED to pin 4

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
#define CLOCKED_STATUS 0 // Data associated with clocked in or out
#define RADIATION_VALUE 1 // Data associated with the calculated radiation value

