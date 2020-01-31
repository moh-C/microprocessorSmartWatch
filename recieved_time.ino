// This data is recieved with serial

int _time=0;
char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(115200);
 Serial.println("<Arduino is ready>");
}

void loop() {
 recvOneChar();
 showNewData();
}

void recvOneChar() {
    if (Serial.available() > 0) {
    receivedChar = Serial.read();
    _time = _time*10 + (receivedChar-48);
    newData = true;
    }
}

void showNewData() {
 if (newData == true) {
    newData = false;
 }
}