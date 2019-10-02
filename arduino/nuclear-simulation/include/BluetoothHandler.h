

void setupBluetooth();

void btLoop();

void btSendInitialSetup(int protocol, char* uniqueID, float radValue, int hazmatStatus, int roomId);

void btSendClockedOut(int protocol, char* uniqueId);

void btSendRadData(int protocol, char* uniqueID, float radValue);

void btSendHazmatStatus(int protocol, int hazmatStatus);

void btSendRoomStatus(int protocol, int roomId);
