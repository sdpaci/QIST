void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
  digitalWriteFast(A0,HIGH);
  delay(0.00005);
  digitalWriteFast(A0,LOW);
  delay(1);
  }
}
