// This data is recieved with serial

char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(9600);
}

void loop() {
 recvOneChar();
 showNewData();
}

void recvOneChar() {
    if (Serial.available() > 0) {
    receivedChar = Serial.read();
    Serial.println(receivedChar);
    newData = true;
    }
}

void showNewData() {
 if (newData == true) {
    newData = false;
 }
}