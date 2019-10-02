

void setupBluetooth();

void btLoop();

void btSendInitialSetup(int, char*, float, int, int);
void btSendClockedOut(int, char*);
void btSendRadData(int , char* ,float );
void btSendHazmatStatus(int, int);
void btSendRoomStatus(int, int);