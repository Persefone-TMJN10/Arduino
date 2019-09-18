#include <UID_List.h>

const char *storedUIDs[] = { // strings to search through
    "34 4Y 5H J7",
    "78 4E 4T H6",
    "85 3A 2G G9",
    "86 3B 2F F8",
    "80 53 80 4D"
 };
 int clockedStatus[] = { //shows status of storedUIDs, 1=clocken in, 0=clocked out
 	0,
    0,
    0,
    0,
    0,
 };

 int len = (sizeof (storedUIDs) / sizeof (*storedUIDs)); // how many elements in array

boolean checkUID(String scannedUID){
    int x = 0;
    if (scannedUID == "34 4Y 5H J7") {
        
        if(clockedStatus[x] == 0) 
                clockedStatus[x] = 1;
            else
                clockedStatus[x] = 0;
        return true;
    } else if (scannedUID == "78 4E 4T H6") {
        x = 1;
        if(clockedStatus[x] == 0) 
                clockedStatus[x] = 1;
            else
                clockedStatus[x] = 0;
        return true;
    } else if (scannedUID == "85 3A 2G G9") {
        x = 2;
        if(clockedStatus[x] == 0) 
                clockedStatus[x] = 1;
            else
                clockedStatus[x] = 0;
        return true;
    } else if (scannedUID == "86 3B 2F F8") {
        x = 3;
        if(clockedStatus[x] == 0) 
                clockedStatus[x] = 1;
            else
                clockedStatus[x] = 0;
        return true;
    } else if (scannedUID == "80 53 80 4D") {
        x = 4;
        if(clockedStatus[x] == 0) 
                clockedStatus[x] = 1;
            else
                clockedStatus[x] = 0;
        return true;
    }
    return false;
}

boolean isClockedIn(String scannedUID) {

int x = 0;
    if (scannedUID == "34 4Y 5H J7") {
        if(clockedStatus[x] == 0) 
                return true;
            else
                return false;
        return true;
    } else if (scannedUID == "78 4E 4T H6") {
        x = 1;
        if(clockedStatus[x] == 0) 
                return true;
            else
                return false;
        return true;
    } else if (scannedUID == "85 3A 2G G9") {
        x = 2;
        if(clockedStatus[x] == 0) 
                return true;
            else
                return false;
        return true;
    } else if (scannedUID == "86 3B 2F F8") {
        x = 3;
        if(clockedStatus[x] == 0) 
                return true;
            else
                return false;
        return true;
    } else if (scannedUID == "80 53 80 4D") {
        x = 4;
        if(clockedStatus[x] == 0) 
                return true;
            else
                return false;
        return true;
    }
    return false;
	
}


