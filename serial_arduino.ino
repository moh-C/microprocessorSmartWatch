int data;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data = Serial.read();
  Serial.println(data);
  delay(1000);
}