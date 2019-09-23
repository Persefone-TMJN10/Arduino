#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000



void rc522ScannerLoop();
void setupRFID();
void getUniqueID();
void authorizeUser();
void storeHexRepresentation(char *b, const byte v);
