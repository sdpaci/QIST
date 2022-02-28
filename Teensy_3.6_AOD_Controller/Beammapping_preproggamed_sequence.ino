//Program to bitmap any sequnce of points by displying only one point at a time in order to avoid conflict.
//Problem is to decide how long to show each point and how to implement this since each point will be gated and gate signal and
//blanking signal must be coupled. Whole sequnce must be repeated long enough to be percieve by eyes (Human eye can perceive event as fast as 100ms.)

int portBPins[] = {16, 17, 19, 18, 0, 1, 32, 25};  //Cols
int portDPins[] = {2, 14, 7, 8, 6, 20, 21, 5};     //Rows
//B Points: row3,cols1-8; col4,5,row1,5,8; col6,rows2,3,4,6,7
//B Points: (B,D): (7,16)(7,17)(7,19)(7,18)(7,0)(7,1)(7,32)(7,25)(4,1)(4,5)(4,8)(5,1)(5,5)(5,8)(6,2)(6,3)(6,4)(6,6)(6,7)
int Bpts[][2] = {{7,16},{7,17},{7,19},{7,18},{7,0},{7,1},{7,32},{7,25},{4,1},{4,5},{4,8},{5,1},{5,5},{5,8},{6,2},{6,3},{6,4},{6,6},{6,7}}
int bptsrows = sizeof(Bpts)/sizeof(Bpts[0]);
int bptscols =sizeof(Bpts[0])/sizeof(int)
// not going to work b/c chararrays diff. sizes
int chararr[][bptsrows][bptscols] = {{{7,16},{7,17},{7,19},{7,18},{7,0},{7,1},{7,32},{7,25},{4,1},{4,5},{4,8},{5,1},{5,5},{5,8},{6,2},{6,3},{6,4},{6,6},{6,7}}}
int numChars = 3;
bool switcher = false;
int seqFirstLetter(int arr[], int count);
int chararrsel( int chararr[], int numChars);

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 7; i++) {
    pinMode(portBPins[i], OUTPUT);
    pinMode(portDPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Repeatedly, run the sequence of letters

  for(i=0; i <=numChars; i++){
//    int selectedPoints[][] = cararrsel(chararr[][][], numChars);
    countp = 0;
      int  Bptslen = sizeof(Bpts) / sizeof(Bpts[0]);
    unsigned long startTimeChar = millis();
    unsigned long endTimChare = startTimeChar;
    unsigned long goalTimeChar = 4000;
    while ((endTimeChar - startTimeChar) <= goalTimeChar) {
      int p[2];
      if (countp <= Bptslen-1) {
        p[] = seqFristLetter(Bpts[][], countp);
      }else{
        countp = 0;
        p[] = seqFristLetter(Bpts[][], countp);
      }
      unsigned long startTimePt = millis();
      unsigned long endTimePt = startTimePt;
      unsigned long goalTimePt = 10;
      while((endTimePt-startTimePt) <=(goaltimePt)){
            digitalWriteFast(p[0], HIGH);
            digitalWriteFast(p[1], HIGH);
            delay(0.01);
            digitalWriteFast(p[0], LOW);
            digitalWriteFast(p[1], LOW);
            delay(0.09);
            endTimePt = millis();  
      }
      countp++;
      endTimeChar = millis();
    }
}
}

int seqFirstLetter(int arr[][], int count) {
  //for each selected point in the first letter show each one at a time
  int  arrsublen = sizeof(arr[0]) / sizeof(arr[0][0]);
  int newarr[arrsublen];
    for(i=0; i <= arrsublen; i++){
      newarr[i] = arr[count][i];
    }
    return newarr[];
}

//
//int chararrsel( int chararr[][][], int numChars){
//  int charsize = sizeof(chararr[0])/sizeof(chararr[0][0]);
//  int pointsize = sizeof(chararr[0][0])/sizeof(chararr[0][0][0]);
//  int siglechar[charsize][pointsize];
//  for(i = 0; i <= charsize-1; i++){
//    for(j=0; j <= pointsize-1; j++){
//      siglechar[i][j] = chararr[numChars][i][j];
//    }
//  }
//  return siglechar[][];
//}





void switcher(int selectedPoint) {
  while(characterSwitcher == false){
    switcher =false;
    delay(10);
    pointSwitcher = true; //if point switcher true stop gate signal and go to the next point and reset pointswitcher false
  }
void switcherChecker(){
  switchCheck = switcher;
  return switchCheck;
}  
//  //run call to point runner here
//  unsigned long startTime = millis();
//  unsigned long endTime = startTime;
//  unsigned long goalTime = 10;
//  bool switcher = false;
//  while ((endTime - startTime) <= goalTime) {
//    
//    endTime = millis();
//  }
//  switcher = true;
}

void pointRunner(int selectedPoint) {
  //Run selectd point by turning of all others and turning it on
  //set all others to LOW and apply gate to signal and treat switching between points as manual innterupt
  //  bool switcher;  //Switch every ten ms?

  while (switcherChecker() == false) {
    digitalFastWrite(selectedPoint, HIGH);
    delay(0.01);
    digitalFastWrite(selectedPoint, LOW);
    delay(0.09);
  }
  //check switcher
  switcher(); //loop back to poin runner if switcher == true
}

//#include <cstdio>
//int arr[][3][2] = {{{1,2},{3,4},{5,6}},{{1,2},{3,4},{5,6}}};
//int main() {
//  int big = sizeof(arr)/sizeof(arr[0]);
//  int med = sizeof(arr[0])/sizeof(arr[0][0]);
//  int small = sizeof(arr[0][0])/sizeof(arr[0][0][0]);
//  printf("%d\n", sizeof(arr));
//  printf("%d\n", sizeof(arr[0]));
//  printf("%d\n", sizeof(arr[0][0]));
//  printf("%d\n", sizeof(arr[0][0][0]));
//  printf("%d\n", sizeof(int));
//  printf("%d\n", big);
//  printf("%d\n", med);
//  printf("%d\n", small);
//  printf("");
//  // printf("%d\n", arr[1][][]);
//  int newarr[med][small];
//  for(int i=0;i<=med-1;i++){
//    for(int j=0; j<=small-1;j++){
//    // printf("%d\n", arr[i][j]);
//    newarr[i][j]=arr[1][i][j];
//    printf("%d\n", newarr[i][j]);
//    }
//  }
//  return 0;
//}
