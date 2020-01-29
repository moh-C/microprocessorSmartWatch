#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
}

void loop() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    printer(tm);
  }
  delay(1000);
}

void printer(tmElements_t _time){
  digitIdentifier((_time.Hour/10)%10);
  digitIdentifier(_time.Hour%10);
}

void digitIdentifier(int number){
  switch(number) {
    case 1:
        Serial.print('One');
        Serial.println();
        break;
    case 2:
        Serial.print('Two');
        Serial.println();
        break;
    case 3:
        Serial.print('Three');
        Serial.println();
        break;
    case 4:
        Serial.print('Four');
        Serial.println();
        break;
    case 5:
        Serial.print('Five');
        Serial.println();
        break;
    case 6:
        Serial.print('Six');
        Serial.println();
        break;
    case 7:
        Serial.print('Seven');
        Serial.println();
        break;
    case 8:
        Serial.print('Eight');
        Serial.println();
        break;
    case 9:
        Serial.print('Nine');
        Serial.println();
        break;
    case 0:
        Serial.print('Zero');
        Serial.println();
        break;
  }
}