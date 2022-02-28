void setup() {
  // put your setup code here, to run once:
  //---------------------------------------------------//
  //PINS 14 - 23 to outputs
  for(int i=14; i<=23; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //---------------------------------------------------//
  //OBJECTIVE:
  //send gate to each of the 8 channels
  //make it programable st. only desired points will
  //receive gate and all others will be set to logic LOW
  //HOW THE AOM CHANNELS CAN BE MANIPULATED: 
  //Each MPDS has 8 channels. First applies each gate to
  //each of 8 points diffracted into a horizontal line. 
  //Second applies each gate to each of 8 vertically 
  //diffracted columns corresponding to the 8 points from
  //AOM 1. Thus, in the resultant grid, gating the channels
  //of AOM 1 will gate the grid column by column and gating
  //the channels of AOM 2 will gate the grid row by row.
  //---------------------------------------------------//
  //Each channel will be gated w/for example a 10Khz gate
  //signal. However, in order to creat the ILLUSION of a 
  //constant image for each character, we must flash is parts
  //repeatedly on the grid faster than can be percived by the
  //human eye, similar to CRT (60Hz refresh rate?). Then there 
  //will be a longer and intenionally perceptible delay between
  //each "scene" or "character to have a video like effect. 
  
  //block for creating code to gate each channel and nest that 
  //in the refresh rate loop.
  //wait 1/60th of 1s between runnig each seq.; update 60 times; then run that loop
  //for ~5s or however long you want it displayed.
  int oneMin = 60000;
  int oneSec = 1000; 
  int period = 0.06;
  const float rate = 16.66; //16.66ms = 60fps
  unsigned long currentTime = 0;
  //myTimer.begin(seqOne, 16666);
  //while( time++ if(time = 16.66
  //declare start time = time(Null);
  //while(elapsedtime - starttime < goaltime){do func.}for(N=1; N<=60; N++){} while(elapsed time = (N/60)goaltime){run sequnces} 
  //elapsedMicros time; 
  unsigned long goalTime = 1000; 
  unsigned long startTime = millis(); /// tic tic tic tic tic tic tic...
  //starttime = timeSince1970-1000; 1000 = timeSince1970-startTime; 
  while((unsigned long currentTime = millis()) - startTime <= goalTime){//tic tic tic... - previoustime ---> 1000
    //for(float N=1; N<=60; N++){               
    //  while(currentTime == ((N/60)*goalTime)){
        seqOne();
        seqTwo();
        seqThree();
        seqFour();
     // }
    //}
  }
  //AFTER ONE FRAME HAS CYCLED ALL CONSTITUENTS TO SCREEN FOR AT LEAST 1s SWITCH TO NEXT FRAME 
  //currentTime = millis();
  //for(int i=0; i<=1000; i+=16.66){
    
  //}
  //while(currentTime<1000){
   // for(int i
 // seqOne();
  //delay(1/0.06);
  //seqTwo();
 
  //refesh rate
  
  }

//In order to display the indiviual points that make up a sequence, certian combinations of rows and/or columns of the grid must be gated
//in certian combinations. Each row and colum of the grid corresponds to a specific channel of the MPDS and each channel is paired with a
//corresponding gate signal of the Arduino. Each gate signal of the Arduino, of course, corresponds to a specific pin on the
//Arduino board which is what will be explicitly coded in this program when refering to the whole pairing (pin, gate signal,
//channel of MPDS, and row or column or grid). 

//LIST OF PINS CORRESPONDING TO EACH ROW & COLUMN:
//|------------------------------------------|
//|Port B Pins: 16, 17, 19, 18,  0, 1, 32, 25|
//|____Columns:  1,  2,  3,  4,  5, 6,  7,  8|
//|------------------------------------------|
//|Port D Pins:  2, 14,  7,  8, 6, 20, 21,  5|
//|_______Rows:  1,  2,  3,  4, 5,  6,  7,  8|
//|------------------------------------------|

//Methods to gate the sequnece of points that make up all or part of each "character" or "frame"

  void seqOne(){
  for(int i=0; 0<=1500; i++){  
  for(int i=firstCh; <=lastCh; i++){ //High of gate signal being applied to desired channels
    digitalFastWrite(i, HIGH);
  }
  delay(0.01); //gate being set high for 10us, for 10kHz gate signal 
  for(int i=firstCh; <=lastCh; i++){ //low of gate signal being applied to desired channels
    digitalFastWrite(i, LOW);
  }
  delay(0.09); //gate being set 90us to achieve T=100us f=10kHz gate signal
  }
  }
  void seqTwo(){
    for(int i=firstCh; <=lastCH; i++){ //High of gate signal being applied to desired channels
    digitalFastWrite(i, HIGH);
  }
  delay(0.01); //gate being set high for 10us, for 10kHz gate signal 
  for(int i=firstCh; <=lastCh; i++){ //low of gate signal being applied to desired channels
    digitalFastWrite(i, LOW);
  }
  delay(0.09); //gate being set 90us to achieve T=100us f=10kHz gate signal
  }

//Making up a seq. for a character "B" to be displayed in the grid. This character cannot be displayed entirely at once and consequently must 
//be broken down into smaller constiuent sequneces which will be cycled rapidly, many many times a second, on the display as to create the optical
//illusion of the entire character being displayed constantly for the duration it is choosen to be displayed.
//Human eye can perceive event as fast as 100ms.

void seqB1(){
  for(int i=0; 0<=1500; i++){  //running gate for arbitrary 1500 cycle for this seq. (max possible ideally for 3 seqs is 3,330 itmes per seq for 3 seqs in 1s)
    int cols[] 
    int rows[]  //TURN THESE OFF make array for ones in neg space to be gated :).
    //Run 1000ms while loop outside loop, and run each seq in loop,ie. continuously and interupt with and interupt aa time determined by
    //...run this gate loop until it is innterupted by more information... 
    //Run all deisred seqs simultaneuosly. If some seqs cannot be displayed simulatenously, they must be cycled thorugh concurrently
    //with the other sequences while awaiting a change from user input as with the other sequences. 
    //For example... have all seqs run through an alg. that checks to see if their are conflict preventing simulatnesous display...
    //if such conflicts exist then minimize the amountof seqs that they must be broken up into and cycle them at an appropraite frame
    //rate continuosly while awwaitingchange from user input of additional programmed instructions to come after.<------
  for(int i=firstCh; <=lastCh; i++){ //High of gate signal being applied to desired channels
    digitalFastWrite(i, HIGH);
  }
  delay(0.01); //gate being set high for 10us, for 10kHz gate signal 
  for(int i=firstCh; <=lastCh; i++){ //low of gate signal being applied to desired channels
    digitalFastWrite(i, LOW);
  }
  delay(0.09); //gate being set 90us to achieve T=100us f=10kHz gate signal
  }
  }
}

void seqB2(){
  for(int i=0; 0<=1500; i++){  //running gate for arbitrary 1500 cycle for this seq. (max possible ideally for 3 seqs is 3,330 itmes per seq for 3 seqs in 1s)
  for(int i=firstCh; <=lastCh; i++){ //High of gate signal being applied to desired channels
    digitalFastWrite(i, HIGH);
  }
  delay(0.01); //gate being set high for 10us, for 10kHz gate signal 
  for(int i=firstCh; <=lastCh; i++){ //low of gate signal being applied to desired channels
    digitalFastWrite(i, LOW);
  }
  delay(0.09); //gate being set 90us to achieve T=100us f=10kHz gate signal
  }
  }
}

void seqB3(){
  for(int i=0; 0<=1500; i++){  //running gate for arbitrary 1500 cycle for this seq. (max possible ideally for 3 seqs is 3,330 itmes per seq for 3 seqs in 1s)
  for(int i=firstCh; <=lastCh; i++){ //High of gate signal being applied to desired channels
    digitalFastWrite(i, HIGH);
  }
  delay(0.01); //gate being set high for 10us, for 10kHz gate signal 
  for(int i=firstCh; <=lastCh; i++){ //low of gate signal being applied to desired channels
    digitalFastWrite(i, LOW);
  }
  delay(0.09); //gate being set 90us to achieve T=100us f=10kHz gate signal
  }
  }
}

//Run series of sequneces for 1000ms and in each seq. gate the necessary channels. The gate must be hard coded and must run
//continusly for the duration of the....I will pick an arbitrary duration. 
//Q: What if we just put the 1000ms while loop in the setup or something and the seqs in the loop...? 
//Ans: Not possible, loop is a func so funcs cant be in loop, nested funcs not allowed in c++
