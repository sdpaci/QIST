char state=0;



void setup() {
  // put your setup code here, to run once:

  //Transmitting AOD
  //Columns
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(25, OUTPUT);
  //Rows
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(5, OUTPUT);
  //blanking
  pinMode(37, OUTPUT);

  //Receiving AOD
  //Columns
  pinMode(15, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //Rows
  pinMode(28, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  //Blanking
  pinMode(36, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Transmitting AOD
  digitalWriteFast(37, HIGH);
  digitalWriteFast(16, HIGH);
  digitalWriteFast(17, HIGH);
  digitalWriteFast(19, HIGH);
  digitalWriteFast(18, HIGH);
  digitalWriteFast(0, HIGH);
  digitalWriteFast(1, HIGH);
  digitalWriteFast(32, HIGH);
  digitalWriteFast(25, HIGH);
  digitalWriteFast(2, HIGH);
  digitalWriteFast(14, HIGH);
  digitalWriteFast(7, HIGH);
  digitalWriteFast(8, HIGH);
  digitalWriteFast(6, HIGH);
  digitalWriteFast(20, HIGH);
  digitalWriteFast(21, HIGH);
  digitalWriteFast(5, HIGH);
  delayMicroseconds(100);
//  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
//
  digitalWriteFast(37, LOW);
  digitalWriteFast(16, LOW);
  digitalWriteFast(17, LOW);
  digitalWriteFast(19, LOW);
  digitalWriteFast(18, LOW);
  digitalWriteFast(0, LOW);
  digitalWriteFast(1, LOW);
  digitalWriteFast(32, LOW);
  digitalWriteFast(25, LOW);
  digitalWriteFast(2, LOW);
  digitalWriteFast(14, LOW);
  digitalWriteFast(7, LOW);
  digitalWriteFast(8, LOW);
  digitalWriteFast(6, LOW);
  digitalWriteFast(20, LOW);
  digitalWriteFast(21, LOW);
  digitalWriteFast(5, LOW);
  delayMicroseconds(900);
//  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");

//  //Receiving AOD
//  //Delay presumably 9us
//  digitalWriteFast(36, HIGH);
//  digitalWriteFast(15, HIGH);
//  digitalWriteFast(22, HIGH);
//  digitalWriteFast(23, HIGH);
//  digitalWriteFast(9, HIGH);
//  digitalWriteFast(10, HIGH);
//  digitalWriteFast(13, HIGH);
//  digitalWriteFast(11, HIGH);
//  digitalWriteFast(12, HIGH);
//  digitalWriteFast(28, HIGH);
//  digitalWriteFast(27, HIGH);
//  digitalWriteFast(29, HIGH);
//  digitalWriteFast(30, HIGH);
//  digitalWriteFast(33, HIGH);
//  digitalWriteFast(24, HIGH);
//  digitalWriteFast(3, HIGH);
//  digitalWriteFast(4, HIGH);
//  delayMicroseconds(10);
////  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
////
//  digitalWriteFast(36, LOW);
//  digitalWriteFast(15, LOW);
//  digitalWriteFast(22, LOW);
//  digitalWriteFast(23, LOW);
//  digitalWriteFast(9, LOW);
//  digitalWriteFast(10, LOW);
//  digitalWriteFast(13, LOW);
//  digitalWriteFast(11, LOW);
//  digitalWriteFast(12, LOW);
//  digitalWriteFast(28, LOW);
//  digitalWriteFast(27, LOW);
//  digitalWriteFast(29, LOW);
//  digitalWriteFast(30, LOW);
//  digitalWriteFast(33, LOW);
//  digitalWriteFast(24, LOW);
//  digitalWriteFast(3, LOW);
//  digitalWriteFast(4, LOW);
//  delayMicroseconds(990);
////  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");


//  digitalWriteFast(37, HIGH);
//  digitalWriteFast(16, HIGH);
//  digitalWriteFast(2, HIGH);
//  digitalWriteFast(17, HIGH);
//  digitalWriteFast(14, HIGH);
//  digitalWriteFast(19, HIGH);
////if (state)
////{
////  digitalWriteFast(1, HIGH);
////  state=0;
////}else
////{
////  digitalWriteFast(1, LOW);
////  state=1;
////}
//  digitalWriteFast(7, HIGH);
//  digitalWriteFast(18, HIGH);
//  digitalWriteFast(8, HIGH);
//  digitalWriteFast(0, HIGH);
//  digitalWriteFast(6, HIGH);
//  digitalWriteFast(1, HIGH);
//  digitalWriteFast(20, HIGH);
//  digitalWriteFast(32, HIGH);
//  digitalWriteFast(21, HIGH);
//  digitalWriteFast(25, HIGH);
//  digitalWriteFast(5, HIGH);  //16/2/17/14/19/7/18/8/0/6/1/20/32/21/25/5
//  delayMicroseconds(10);
////  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
//
//  digitalWriteFast(37, LOW);
//  digitalWriteFast(16, LOW);
//  digitalWriteFast(2, LOW);
//  digitalWriteFast(17, LOW);
//  digitalWriteFast(14, LOW);
//  digitalWriteFast(19, LOW);
//  digitalWriteFast(7, LOW);
//  digitalWriteFast(18, LOW);
//  digitalWriteFast(8, LOW);
//  digitalWriteFast(0, LOW);
//  digitalWriteFast(6, LOW);
//  digitalWriteFast(1, LOW);
//  digitalWriteFast(20, LOW);
//  digitalWriteFast(32, LOW);
//  digitalWriteFast(21, LOW);
//  digitalWriteFast(25, LOW);
//  digitalWriteFast(5, LOW);
//  delayMicroseconds(990);
////  asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
  
}
