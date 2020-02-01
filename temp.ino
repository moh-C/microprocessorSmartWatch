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
  zero(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  zero(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  zero(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  zero(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  one(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  one(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  one(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  one(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  two(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  two(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  two(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  two(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  three(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  three(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  three(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  three(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  four(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  four(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  four(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  four(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  five(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  five(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  five(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  five(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  six(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  six(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  six(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  six(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  seven(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  seven(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  seven(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  seven(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  eight(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  eight(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  eight(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  eight(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
  nine(seg1_a,seg1_b,seg1_c,seg1_d,seg1_e,seg1_f,seg1_g);
  nine(seg2_a,seg2_b,seg2_c,seg2_d,seg2_e,seg2_f,seg2_g);
  nine(seg3_a,seg3_b,seg3_c,seg3_d,seg3_e,seg3_f,seg3_g);
  nine(seg4_a,seg4_b,seg4_c,seg4_d,seg4_e,seg4_f,seg4_g);
  delay(1000);
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