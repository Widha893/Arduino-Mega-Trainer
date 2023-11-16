int IN[4];
void setup() {
  Serial.begin(9600);
  for (int i=0;i<4;i++){
    pinMode(IN[i],OUTPUT);
  }
}

void loop() {
  for (int i=0;i<4;i++){
    digitalWrite(IN[i],HIGH);
  }
}
