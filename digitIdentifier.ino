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
  digitIdentifier((_time.Second/10)%10);
  //digitIdentifier(_time.Second%10);
}

void digitIdentifier(int number){
  switch(number) {
    case 1:
        one(a,b,c,d,e,f,g);
        break;
    case 2:
        two(a,b,c,d,e,f,g);
        break;
    case 3:
        three(a,b,c,d,e,f,g);
        break;
    case 4:
        four(a,b,c,d,e,f,g);
        break;
    case 5:
        five(a,b,c,d,e,f,g);
        break;
    case 6:
        six(a,b,c,d,e,f,g);
        break;
    case 7:
        seven(a,b,c,d,e,f,g);
        break;
    case 8:
        eight(a,b,c,d,e,f,g);
        break;
    case 9:
        nine(a,b,c,d,e,f,g);
        break;
    case 0:
        zero(a,b,c,d,e,f,g);
        break;
  }
}