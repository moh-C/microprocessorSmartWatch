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
  tmElements_t tm;

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
 recvOneChar();
 showNewData();
}

void recvOneChar() {
    if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if(receivedChar >= '0' && receivedChar <= '9') {
      _time = _time*10 + (receivedChar-48);
      Serial.println(_time);
      if (getTime2(__TIME__,_time)) {
          if (RTC.write(tm)) {}
      }
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

bool getTime2(const char *str, int _time)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = _time/100;
  tm.Minute = _time%100;
  tm.Second = Sec;
  return true;
}