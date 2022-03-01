/*
 * PCB_Teensy_Code_Gate_2_AOD_2_AOM.ino
 * 
 * Created: 3/11/2021
 * Author: Steven Paci Jr.
 */
 void setup() {
  // put your setup code here, to run once:
  //Set digital I/O Pins being used to Outputs
  //transmitting AOD
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(47, OUTPUT);
  //recieving AOD
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(54, OUTPUT);
  pinMode(55, OUTPUT);
  //SMA pins
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Write pins high
  //transmitting AOD
  digitalWriteFast(29, HIGH);
  digitalWriteFast(30, HIGH);
  digitalWriteFast(1, HIGH);
  digitalWriteFast(0, HIGH);
  digitalWriteFast(18, HIGH);
  digitalWriteFast(19, HIGH);
  digitalWriteFast(17, HIGH);
  digitalWriteFast(16, HIGH);
  digitalWriteFast(31, HIGH);
  digitalWriteFast(5, HIGH);
  digitalWriteFast(21, HIGH);
  digitalWriteFast(20, HIGH);
  digitalWriteFast(6, HIGH);
  digitalWriteFast(8, HIGH);
  digitalWriteFast(7, HIGH);
  digitalWriteFast(14, HIGH);
  digitalWriteFast(2, HIGH);
  digitalWriteFast(47, HIGH);
  //recieving AOD
  digitalWriteFast(9, HIGH);
  digitalWriteFast(10, HIGH);
  digitalWriteFast(11, HIGH);
  digitalWriteFast(12, HIGH);
  digitalWriteFast(13, HIGH);
  digitalWriteFast(15, HIGH);
  digitalWriteFast(22, HIGH);
  digitalWriteFast(23, HIGH);
  digitalWriteFast(36, HIGH);
  digitalWriteFast(46, HIGH);
  digitalWriteFast(48, HIGH);
  digitalWriteFast(49, HIGH);
  digitalWriteFast(50, HIGH);
  digitalWriteFast(51, HIGH);
  digitalWriteFast(52, HIGH);
  digitalWriteFast(53, HIGH);
  digitalWriteFast(54, HIGH);
  digitalWriteFast(55, HIGH);
  //SMA pins
  digitalWriteFast(26, HIGH);
  digitalWriteFast(27, HIGH);
  delayMicroseconds(10); //delay for 10 us

  //Write pins low
  //transmitting AOD
  digitalWriteFast(29, LOW);
  digitalWriteFast(30, LOW);
  digitalWriteFast(1, LOW);
  digitalWriteFast(0, LOW);
  digitalWriteFast(18, LOW);
  digitalWriteFast(19, LOW);
  digitalWriteFast(17, LOW);
  digitalWriteFast(16, LOW);
  digitalWriteFast(31, LOW);
  digitalWriteFast(5, LOW);
  digitalWriteFast(21, LOW);
  digitalWriteFast(20, LOW);
  digitalWriteFast(6, LOW);
  digitalWriteFast(8, LOW);
  digitalWriteFast(7, LOW);
  digitalWriteFast(14, LOW);
  digitalWriteFast(2, LOW);
  digitalWriteFast(47, LOW);
  //recieving AOD
  digitalWriteFast(9, LOW);
  digitalWriteFast(10, LOW);
  digitalWriteFast(11, LOW);
  digitalWriteFast(12, LOW);
  digitalWriteFast(13, LOW);
  digitalWriteFast(15, LOW);
  digitalWriteFast(22, LOW);
  digitalWriteFast(23, LOW);
  digitalWriteFast(36, LOW);
  digitalWriteFast(46, LOW);
  digitalWriteFast(48, LOW);
  digitalWriteFast(49, LOW);
  digitalWriteFast(50, LOW);
  digitalWriteFast(51, LOW);
  digitalWriteFast(52, LOW);
  digitalWriteFast(53, LOW);
  digitalWriteFast(54, LOW);
  digitalWriteFast(55, LOW);
  //SMA pins
  digitalWriteFast(26, LOW);
  digitalWriteFast(27, LOW);
  delayMicroseconds(90); //delay for 90 us
}
