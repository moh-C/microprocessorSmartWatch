#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

int _time = 0;
char receivedChar;
boolean newData = false;
tmElements_t tm;

int seg1_e = 13;
int seg1_d = 12;
int seg1_c = 11;
int seg1_b = 22;
int seg1_a = 23;
int seg1_f = 24;
int seg1_g = 25;
int seg2_e = 26;
int seg2_d = 27;
int seg2_c = 28;
int seg2_b = 29;
int seg2_a = 30;
int seg2_f = 31;
int seg2_g = 32;
int seg3_e = 46;
int seg3_d = 45;
int seg3_c = 44;
int seg3_b = 43;
int seg3_a = 42;
int seg3_f = 41;
int seg3_g = 40;
int seg4_e = 52;
int seg4_d = 53;
int seg4_c = 50;
int seg4_b = 51;
int seg4_a = 49;
int seg4_f = 48;
int seg4_g = 47;

void setup() {
 Serial.begin(9600);
 pinMode(seg1_a,OUTPUT);
  pinMode(seg1_b,OUTPUT);
  pinMode(seg1_c,OUTPUT);
  pinMode(seg1_d,OUTPUT);
  pinMode(seg1_e,OUTPUT);
  pinMode(seg1_f,OUTPUT);
  pinMode(seg1_g,OUTPUT);
  pinMode(seg2_a,OUTPUT);
  pinMode(seg2_b,OUTPUT);
  pinMode(seg2_c,OUTPUT);
  pinMode(seg2_d,OUTPUT);
  pinMode(seg2_e,OUTPUT);
  pinMode(seg2_f,OUTPUT);
  pinMode(seg2_g,OUTPUT);
  pinMode(seg3_a,OUTPUT);
  pinMode(seg3_b,OUTPUT);
  pinMode(seg3_c,OUTPUT);
  pinMode(seg3_d,OUTPUT);
  pinMode(seg3_e,OUTPUT);
  pinMode(seg3_f,OUTPUT);
  pinMode(seg3_g,OUTPUT);
  pinMode(seg4_a,OUTPUT);
  pinMode(seg4_b,OUTPUT);
  pinMode(seg4_c,OUTPUT);
  pinMode(seg4_d,OUTPUT);
  pinMode(seg4_e,OUTPUT);
  pinMode(seg4_f,OUTPUT);
  pinMode(seg4_g,OUTPUT);
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
    printer(tm);
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
      if(_time>10000) {
        _time %= 1000;
      }
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

void printer(tmElements_t _time){
  digitIdentifier01((_time.Hour/10)%10);
  digitIdentifier02((_time.Hour)%10);
  digitIdentifier03((_time.Minute/10)%10);
  digitIdentifier04((_time.Minute)%10);
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

void digitIdentifier01(int number){
  switch(number) {
    case 1:
        one(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 2:
        two(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 3:
        three(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 4:
        four(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 5:
        five(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 6:
        six(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 7:
        seven(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 8:
        eight(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 9:
        nine(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
    case 0:
        zero(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
        break;
  }
}

void digitIdentifier02(int number){
  switch(number) {
    case 1:
        one(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 2:
        two(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 3:
        three(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 4:
        four(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 5:
        five(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 6:
        six(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 7:
        seven(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 8:
        eight(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 9:
        nine(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
    case 0:
        zero(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
        break;
  }
}

void digitIdentifier03(int number){
  switch(number) {
    case 1:
        one(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 2:
        two(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 3:
        three(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 4:
        four(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 5:
        five(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 6:
        six(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 7:
        seven(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 8:
        eight(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 9:
        nine(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
    case 0:
        zero(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
        break;
  }
}

void digitIdentifier04(int number){
  switch(number) {
    case 1:
        one(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 2:
        two(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 3:
        three(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 4:
        four(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 5:
        five(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 6:
        six(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 7:
        seven(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 8:
        eight(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 9:
        nine(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
    case 0:
        zero(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
        break;
  }
}

void zero(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,HIGH);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,LOW);
}

void one(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,LOW);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,LOW);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,LOW);
  digitalWrite(g_block,LOW);
}

void two(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,LOW);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,HIGH);
  digitalWrite(f_block,LOW);
  digitalWrite(g_block,HIGH);
}

void three(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,LOW);
  digitalWrite(g_block,HIGH);
}

void four(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,LOW);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,LOW);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,HIGH);
}

void five(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,LOW);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,HIGH);
}

void six(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,LOW);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,HIGH);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,HIGH);
}

void seven(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,LOW);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,LOW);
  digitalWrite(g_block,LOW);
}

void eight(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,HIGH);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,HIGH);
}


void nine(int a_block, int b_block, int c_block, int d_block, int e_block, int f_block, int g_block){
  digitalWrite(a_block,HIGH);
  digitalWrite(b_block,HIGH);
  digitalWrite(c_block,HIGH);
  digitalWrite(d_block,HIGH);
  digitalWrite(e_block,LOW);
  digitalWrite(f_block,HIGH);
  digitalWrite(g_block,HIGH);
}