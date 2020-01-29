#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

int a = 9;
int b = 10;
int c = 8;
int d = 7;
int e = 6;
int f = 11;
int g = 12;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
  tmElements_t tm;

  if (RTC.read(tm)) {
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