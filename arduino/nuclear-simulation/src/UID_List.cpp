#include <UID_List.h>


char buffer[128]; // just a buffer to print to
//char *ScannedUID; // string we want to find
const char *storedUIDs[] = { // strings to search through
    "34 4Y 5H J7",
    "78 4E 4T H6",
    "85 3A 2G G9",
    "86 3B 2F F8",
 };
 int clockedStatus[] = { //shows status of storedUIDs, 1=clocken in, 0=clocked out
 	0,
    0,
    0,
    0,
    0,
 };

 int len = (sizeof (storedUIDs) / sizeof (*storedUIDs)); // how many elements in array
 static int x; // generic loop counter

boolean checkUID(char * scannedUID){
 for(int x = 0; x < len; x++) {
    sprintf (buffer, "Looking for %s (at index %d)...", scannedUID, x);
     Serial.print (buffer);
     if (strcmp (scannedUID, storedUIDs[x]) == 0) { // this is the key:
        sprintf (buffer, "Found %s in array at index %d!\r\n", storedUIDs[x], x);
        Serial.print (buffer);
                if(clockedStatus[x] == 0) 
        	clockedStatus[x] = 1;
        else
        	clockedStatus[x] = 0;
        return true;
    } else {
           sprintf (buffer, "Fail. %s is not %s at index %d!\r\n", scannedUID, storedUIDs[x], x);
           Serial.print (buffer);
       }
 }
 return false;
}
boolean isClockedIn(char * scannedUID) {

	for(int x = 0; x < len; x++) {
     if (strcmp (scannedUID, storedUIDs[x]) == 0) {
        if(clockedStatus[x] == 1){
        Serial.print("Clocked In\n");   
        	return true;
        }
        else
            Serial.print("Clocked out\n"); 
        return false;
      }
  }
	
}


