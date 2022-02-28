void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
 /* while(1){
  analogWriteFrequency(A0, 100000);
  analogWriteResolution(10);
  analogWrite(A0, 106);
  delay(15000);  
  analogWriteFrequency(A0, 1000000);
  analogWriteResolution(5); 
  analogWrite(A0, 4.8);
  delay(15000);
  analogWriteFrequency(A0, 500000);
  analogWriteResolution(6);
  analogWrite(A0, 7.66);
  delay(15000);
  analogWriteFrequency(A0, 10000);
  analogWriteResolution(12);
  analogWrite(A0, 409.5);
  delay(15000);
  analogWriteFrequency(A0, 2000000);
  analogWriteResolution(4);
  analogWrite(A0, 2);
  }*/
  analogWriteFrequency(A0, 10000);
  analogWriteResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(A0, 40); //T = 10us, pw = 55ns, f = 100kHz
}
