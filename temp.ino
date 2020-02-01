#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

int _time = 0;
char receivedChar;
boolean newData = false;
tmElements_t tm;

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
    if(receivedChar >= '0' && receivedChar <= '9') {
      _time = _time*10 + (receivedChar-48);
      Serial.println(_time);
    }
    newData = true;
    }
}

void showNewData() {
 if (newData == true) {
    newData = false;
 }
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

bool getTime(const char *str, int _time)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = _time/100;
  tm.Minute = _time%100;
  tm.Second = Sec;
  return true;
}