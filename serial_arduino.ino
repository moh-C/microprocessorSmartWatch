int data;

void setup() {
  Serial.begin(115200);
}

void loop() {
  data = Serial.read();
  Serial.write();
  delay(1000);
}