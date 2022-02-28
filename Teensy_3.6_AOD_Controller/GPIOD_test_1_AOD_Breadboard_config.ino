byte firstByte;
int a=0;
IntervalTimer myTimer;
void setup() {
  // put your setup code here, to run once:

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
  //  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);

  myTimer.begin(func, 1);
}

void func(){

    GPIOD_PDOR = B11111111;
    asm("nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
    GPIOD_PDOR = B00000000;



}

void loop() {
  // put your main code here, to run repeatedly:
  
//    GPIOD_PDOR = B10000000;
//    asm("nop; nop; nop; nop; nop; nop; nop; nop; nop;nop; nop; nop; nop; nop;");
//
//    GPIOD_PDOR = B00000000;

   
  
}
